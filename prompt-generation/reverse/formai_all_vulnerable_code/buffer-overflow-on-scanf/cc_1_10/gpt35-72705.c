//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void print_watermarked_text(char* text, char* watermark);
char* generate_watermark(char* text, char* secret);
int has_watermark(char* text, char* secret);
void remove_watermark(char* text, char* secret);

int main() {
  char text[MAX_SIZE];
  char secret[MAX_SIZE];
  char* watermark;
  int choice;

  printf("Enter the text to be watermarked: ");
  fgets(text, MAX_SIZE, stdin);
  printf("Enter the secret key: ");
  fgets(secret, MAX_SIZE, stdin);

  do {
    printf("\nChoose an option:\n");
    printf("1. Print watermarked text\n");
    printf("2. Generate watermark\n");
    printf("3. Check if text has watermark\n");
    printf("4. Remove watermark\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        watermark = generate_watermark(text, secret);
        print_watermarked_text(text, watermark);
        break;

      case 2:
        watermark = generate_watermark(text, secret);
        printf("\nWatermark: %s\n", watermark);
        break;

      case 3:
        if(has_watermark(text, secret)) {
          printf("\nThe text has a watermark.\n");
        } else {
          printf("\nThe text does not have a watermark.\n");
        }
        break;

      case 4:
        remove_watermark(text, secret);
        printf("\nWatermark successfully removed from text.\n");
        break;

      case 5:
        printf("\nGoodbye!\n");
        break;

      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  } while(choice != 5);
  
  return 0;
}

void print_watermarked_text(char* text, char* watermark) {
  char* cursor = text;
  int position = 0;

  // Print the watermarked text
  while(*cursor != '\0') {
    if(position % 2 == 0) {
      // Print character from watermark
      printf("%c", *watermark);
      watermark++;
    } else {
      // Print character from text
      printf("%c", *cursor);
      cursor++;
    }

    position++;
  }
}

char* generate_watermark(char* text, char* secret) {
  // Generate watermark string
  char* watermark = (char*)malloc(sizeof(char) * strlen(secret));
  char* cursor = watermark;

  for(int i = 0; i < strlen(secret); i++) {
    *cursor = text[i] ^ secret[i];
    cursor++;
  }

  return watermark;
}

int has_watermark(char* text, char* secret) {
  // Check if text has watermark
  for(int i = 0; i < strlen(secret); i++) {
    if((text[i] ^ secret[i]) != text[i + 1]) {
      return 0;
    }
  }

  return 1;
}

void remove_watermark(char* text, char* secret) {
  int position = 0;

  // Remove watermark from text
  for(int i = 0; i < strlen(secret); i++) {
    text[i] = text[i] ^ secret[i];
    position++;
  }

  // Shift remaining characters left
  char* cursor = text + position;
  while(*cursor != '\0') {
    *cursor = *(cursor + 1);
    cursor++;
  }
}