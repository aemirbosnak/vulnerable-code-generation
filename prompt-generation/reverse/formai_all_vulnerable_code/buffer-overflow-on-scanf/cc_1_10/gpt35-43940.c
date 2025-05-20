//FormAI DATASET v1.0 Category: Image Steganography ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char *filename, char *message);
void decode(char *filename);

int main(){

  char filename[100];
  char message[1000];
  int choice;

  printf("Enter the filename (with extension): ");
  scanf("%s",filename);

  printf("\nEnter 1 to encode or 2 to decode: ");
  scanf("%d",&choice);

  fflush(stdin);

  if(choice == 1){

    printf("\nEnter the message to be encoded: ");
    fgets(message,1000,stdin);
    fflush(stdin);
    encode(filename,message);

  } else if (choice == 2){

    decode(filename);

  } else {

    printf("\nInvalid choice.");

  }

  return 0;

}

void encode(char *filename, char *message){

  FILE *fptr;
  char ch, bit, new_ch;
  int index, message_length;

  fptr = fopen(filename,"rb+");
  if(fptr != NULL){

    fseek(fptr, 0, SEEK_END);
    message_length = strlen(message);
    rewind(fptr);

    for(int i=0;i<message_length;i++){

      index = 0;
      ch = message[i];

      while(index < 8){

        bit = (ch >> index) & 1;
        fread(&new_ch,1,1,fptr);
        new_ch = (new_ch & 0xFE) | bit;
        fseek(fptr,-1,SEEK_CUR);
        fwrite(&new_ch,1,1,fptr);
        index++;

      }

    }

    fclose(fptr);
    printf("\nMessage encoded successfully.");

  } else {

    printf("\nUnable to open the file.");

  }

}

void decode(char *filename){

  FILE *fptr;
  char ch, bit, message[1000];
  int index = 0, message_length = 0;

  fptr = fopen(filename,"rb");
  if(fptr != NULL){

    fseek(fptr, 0, SEEK_END);
    message_length = ftell(fptr) / 8;
    rewind(fptr);

    for(int i=0;i<message_length;i++){

      ch = 0;
      index = 0;

      while(index < 8){

        fseek(fptr,-1,SEEK_CUR);
        fread(&bit,1,1,fptr);
        bit = bit & 1;
        ch = ch | (bit << index);
        fseek(fptr,-1,SEEK_CUR);
        index++;

      }

      message[i] = ch;

    }

    fclose(fptr);
    printf("\nThe decoded message is: %s",message);

  } else {

    printf("\nUnable to open the file.");

  }

}