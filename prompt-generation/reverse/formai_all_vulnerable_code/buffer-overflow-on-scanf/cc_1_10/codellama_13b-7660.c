//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT_LENGTH 100

void print_menu() {
  printf("Please enter a sentence: ");
  printf("1. Analyze Sentiment\n");
  printf("2. Exit\n");
  printf("Enter your choice: ");
}

int get_choice() {
  int choice;
  scanf("%d", &choice);
  return choice;
}

void analyze_sentiment(char* text) {
  int positive_count = 0;
  int negative_count = 0;

  for (int i = 0; i < strlen(text); i++) {
    if (text[i] == '+' || text[i] == ':') {
      positive_count++;
    } else if (text[i] == '-' || text[i] == ':') {
      negative_count++;
    }
  }

  if (positive_count > negative_count) {
    printf("The sentiment of the sentence is positive.\n");
  } else if (negative_count > positive_count) {
    printf("The sentiment of the sentence is negative.\n");
  } else {
    printf("The sentiment of the sentence is neutral.\n");
  }
}

int main() {
  char text[MAX_TEXT_LENGTH];
  int choice;

  while (1) {
    print_menu();
    choice = get_choice();

    if (choice == 1) {
      printf("Enter a sentence: ");
      scanf("%s", text);
      analyze_sentiment(text);
    } else if (choice == 2) {
      break;
    } else {
      printf("Invalid choice.\n");
    }
  }

  return 0;
}