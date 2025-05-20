//FormAI DATASET v1.0 Category: Digital Diary ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  int choice, diarycount;
  printf("Welcome to Puzzling Digital Diary, a unique way to keep your memories encrypted\n");
  printf("How many diary entries would you like to create?\n");
  scanf("%d", &diarycount);

  char** entry_array = (char**) malloc(diarycount * sizeof(char*));
  
  for (int i = 0; i < diarycount; i++) {
    printf("Enter the text for Diary Entry %d:\n", i+1);
    char entry[1000];
    scanf("%s", entry);
	
    int len = strlen(entry);
    char encrypted_text[len+1];
  
    for (int j=0; j<len; j++) {
      encrypted_text[j] = entry[len-1-j] + 3;
      if (encrypted_text[j] > 'z') {
        encrypted_text[j] = encrypted_text[j] - 26;
      }
    }
    encrypted_text[len] = '\0';
    entry_array[i] = (char*) malloc((len+1) * sizeof(char));
    strcpy(entry_array[i], encrypted_text);
  }

  while (1) {
    printf("\nWhat would you like to do?\n");
    printf("1. View all Diary Entries\n");
    printf("2. View a Specific Diary Entry\n");
    printf("3. Exit the program\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1: 
        printf("\nAll Diary Entries:\n");
        for (int i = 0; i<diarycount; i++) {
          printf("Entry %d: ", i+1);
          for (int j=0; j<strlen(entry_array[i]); j++) {
            printf("%c", entry_array[i][j]);
          }
          printf("\n");
        }
        break;
      case 2:
        printf("\nEnter the Entry Number you want to view:\n");
        int entry_num;
        scanf("%d", &entry_num);
        if (entry_num <= diarycount && entry_num >= 1) {
          printf("Diary Entry %d: ", entry_num);
          for (int j=0; j<strlen(entry_array[entry_num-1]); j++) {
            printf("%c", entry_array[entry_num-1][j]);
          }
          printf("\n");
        } 
        else {
          printf("Sorry, there is no Diary Entry for the selected entry number\n");
        }
        break;
      case 3:
        printf("\nExiting the program...\n");
        for (int i=0; i<diarycount; i++) {
          free(entry_array[i]);
        }
        free(entry_array);
        exit(0);
      default:
        printf("\nInvalid Choice, Please try again!\n");
        break;
    }
  }
  return 0;
}