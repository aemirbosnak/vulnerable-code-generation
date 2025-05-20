//FormAI DATASET v1.0 Category: Image compression ; Style: bold
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXELS 256
#define MAX_SYMBOLS (MAX_PIXELS+1)

typedef struct Symbol{
  int count;
  int bits;
  int code;
  int parent;
}Symbol;

Symbol symbol_table[MAX_SYMBOLS];
int num_symbols = 0;

int frequencies[MAX_PIXELS] = {0};
int pixels[MAX_PIXELS] = {0};
int num_pixels = 0;

int stack[MAX_SYMBOLS];
int top = -1;

void push(int val){
  top++;
  stack[top] = val;
}

int pop(){
  int val = stack[top];
  top--;
  return val;
}

void sort_by_frequency(Symbol* symbols, int num_symbols){
  int i, j;
  for(i=0; i<num_symbols-1; i++){
    for(j=0; j<num_symbols-i-1; j++){
      if(symbols[j].count < symbols[j+1].count){
        Symbol temp = symbols[j];
        symbols[j] = symbols[j+1];
        symbols[j+1] = temp;
      }
    }
  }
}

void init_symbol_table(){
  int i;
  for(i=0; i<=MAX_PIXELS; i++){
    symbol_table[i].count = 0;
    symbol_table[i].bits = 0;
    symbol_table[i].code = 0;
    symbol_table[i].parent = 0;
  }
}

void print_symbol_table(){
  int i;
  for(i=0; i<num_symbols; i++){
    printf("%d (%d/%d): %d/%d ", 
      i,
      symbol_table[i].parent,
      symbol_table[symbol_table[i].parent].count,
      symbol_table[i].count,
      symbol_table[i].bits);
    printf("%d\n", symbol_table[i].code);
  }
}

void encode_tree(int root, int bits, int code){
  symbol_table[root].bits = bits;
  symbol_table[root].code = code;
  if(root <= MAX_PIXELS){
    return;
  }
  encode_tree(root-1, bits+1, code<<1);
  encode_tree(symbol_table[root].parent, bits+1, (code<<1)+1);
}

void Huffman_encode(){
  int i, least1, least2;
  init_symbol_table();
  num_symbols = num_pixels;

  for(i=0; i<num_pixels; i++){
    symbol_table[i].count = frequencies[i];
    pixels[i] = i;
  }

  while(num_symbols > 1){
    sort_by_frequency(symbol_table, num_symbols);

    least1 = pop();
    least2 = pop();

    symbol_table[num_symbols].count = symbol_table[least1].count + symbol_table[least2].count;
    
    symbol_table[least1].parent = num_symbols;
    symbol_table[least2].parent = num_symbols;

    push(num_symbols);
    num_symbols++;
  }

  encode_tree(num_symbols-1, 0, 0);
}

void generate_frequencies(){
  int i, j;
  for(i=0; i<num_pixels; i++){
    int pixel = pixels[i];
    int found = 0;
    for(j=0; j<num_symbols && !found; j++){
      if(pixel == symbol_table[j].count){
        symbol_table[j].count++;
        found = 1;
      }
    }
    if(!found){
      symbol_table[num_symbols].count = 1;
      symbol_table[num_symbols].parent = -1;
      symbol_table[num_symbols].code = 0;
      symbol_table[num_symbols].bits = 0;
      num_symbols++;
    }
  }
}

int main(){
  int i, num_bits = 0, num_compressed_bits = 0, num_padding_bits = 0;
  FILE* infile = fopen("image.ppm", "r");
  FILE* outfile = fopen("image.bin", "wb");

  if(!infile){
    printf("Error opening input file.\n");
    return 1;
  }

  if(!outfile){
    printf("Error opening output file.\n");
    return 1;
  }

  char format[3];
  int width, height, maxval;
  fscanf(infile, "%s\n%d %d\n%d\n", format, &width, &height, &maxval);

  num_pixels = width * height;

  for(i=0; i<num_pixels; i++){
    int pixel;
    fscanf(infile, "%d", &pixel);
    frequencies[pixel]++;
    pixels[i] = pixel;
  }

  generate_frequencies();

  Huffman_encode();

  for(i=0; i<num_pixels; i++){
    int pixel = pixels[i];
    num_bits += symbol_table[pixel].bits;
    num_compressed_bits += fwrite(&symbol_table[pixel].code, 1, symbol_table[pixel].bits, outfile);
  }

  num_padding_bits = 8 - (num_compressed_bits % 8);
  if(num_padding_bits == 8){
    num_padding_bits = 0;
  }

  for(i=0; i<num_padding_bits; i++){
    int bit = 0;
    fwrite(&bit, 1, 1, outfile);
  }

  fclose(infile);
  fclose(outfile);

  printf("Original file size: %d bytes\n", num_pixels);
  printf("Compressed file size: %d bytes\n", (num_compressed_bits + num_padding_bits) / 8);
  printf("Compression ratio: %.2f%%\n", ((float)(num_compressed_bits + num_padding_bits) / (float)num_pixels) * 100.0);

  return 0;
}