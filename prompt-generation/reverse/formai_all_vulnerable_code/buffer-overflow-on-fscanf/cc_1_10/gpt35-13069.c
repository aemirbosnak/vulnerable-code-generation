//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASH_LENGTH 10
#define MAX_TEXT_LENGTH 1000

typedef struct watermark
{
    char text[MAX_TEXT_LENGTH];
    char hash[HASH_LENGTH];
} watermark;

void create_watermark(char* text, watermark* wm)
{
    strcpy(wm->text, text);
    char hash[HASH_LENGTH];
    int i;
    for(i=0;i<HASH_LENGTH-1;i++)
    {
        hash[i] = rand()%10 + 48;   //ASCII value of 0-9
    }
    hash[i] = '\0';
    strcpy(wm->hash, hash);
}

void display_watermark(watermark* wm)
{
    printf("Text: %s\n", wm->text);
    printf("Hash: %s\n", wm->hash);
}

void embed_watermark(char* source_file, char* target_file, watermark* wm)
{
    FILE *fs, *ft;
    fs = fopen(source_file,"rb");
    if(fs == NULL)
    {
        printf("Source file not found!\n");
        return;
    }
    ft = fopen(target_file,"wb");
    char ch;
    int bit_no = 0, hash_bit_no = 0;
    char hash_bit;
    while(fscanf(fs,"%c",&ch)!=EOF)
    {
        if(bit_no<MAX_TEXT_LENGTH*8)
        {
            char bit = ((wm->text[bit_no/8] >> (7-(bit_no%8))) & 1) ? '1' : '0';
            fprintf(ft,"%c",ch & ~1 | bit);
            bit_no++;
        }
        else if(hash_bit_no<HASH_LENGTH*8)
        {
            hash_bit = ((wm->hash[hash_bit_no/8] >> (7-(hash_bit_no%8))) & 1) ? '1' : '0';
            fprintf(ft,"%c",ch & ~1 | hash_bit);
            hash_bit_no++;
        }
        else
        {
            fprintf(ft,"%c",ch);
        }
    }
    fclose(fs);
    fclose(ft);
}

int extract_watermark(char* steg_file, watermark* wm)
{
    FILE *fs;
    fs = fopen(steg_file,"rb");
    if(fs == NULL)
    {
        printf("Stego file not found!\n");
        return 0;
    }
    char ch, text_bit, hash_bit;
    int bit_no = 0, hash_bit_no = 0;
    char text[MAX_TEXT_LENGTH], hash[HASH_LENGTH];
    memset(text, '\0', sizeof(text));
    memset(hash, '\0', sizeof(hash));
    while(fscanf(fs,"%c",&ch)!=EOF && bit_no<MAX_TEXT_LENGTH*8+HASH_LENGTH*8)
    {
        if(bit_no<MAX_TEXT_LENGTH*8)
        {
            text_bit = (ch & 1) ? '1' : '0';
            text[bit_no/8] |= (text_bit<<(7-(bit_no%8)));
            bit_no++;
        }
        else if(hash_bit_no<HASH_LENGTH*8)
        {
            hash_bit = (ch & 1) ? '1' : '0';
            hash[hash_bit_no/8] |= (hash_bit<<(7-(hash_bit_no%8)));
            hash_bit_no++;
        }
        else
        {
            break;
        }
    }
    fclose(fs);
    if(hash_bit_no != HASH_LENGTH*8)
    {
        printf("Watermark not found!\n");
        return 0;
    }
    else
    {
        create_watermark(text, wm);
        if(strcmp(hash, wm->hash) == 0)
        {
            return 1;
        }
        else
        {
            printf("Corrupted watermark!\n");
            return -1;
        }
    }
}

void test_digital_watermarking()
{
    watermark wm;
    create_watermark("This is a sample text to test digital watermarking", &wm);
    embed_watermark("source_image.png", "watermarked_image.png", &wm);
    watermark wm_extracted;
    int result = extract_watermark("watermarked_image.png", &wm_extracted);
    if(result)
    {
        printf("Watermark found!\n");
        display_watermark(&wm_extracted);
    }
    else if(result == 0)
    {
        printf("Watermark not found!\n");
    }
}

int main()
{
    test_digital_watermarking();
    return 0;
}