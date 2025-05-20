//FormAI DATASET v1.0 Category: Digital Diary ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry { // Declare struct for entry
  char date[15];
  char title[100];
  char content[1000];
};

int main() {
  struct entry diary[365]; // Create an array of entries for everyday of year
  int option;
  int count = 0;

  while(1) {
    printf("Welcome to your Digital Diary!\n");
    printf("Choose an option:\n");
    printf("1. Create a new entry\n");
    printf("2. View all entries\n");
    printf("3. Edit an entry\n");
    printf("4. Delete an entry\n");
    printf("5. Exit\n");
    scanf("%d", &option); // Get user inputs

    switch(option) {
      case 1:
        printf("Enter the date (DD/MM/YYYY): ");
        scanf("%s", &diary[count].date);
        printf("Enter the title: ");
        scanf("%s", &diary[count].title);
        printf("Enter the content: ");
        scanf("%s", &diary[count].content);
        count++; // Increment the counter variable
        printf("Entry created!\n\n");
        break;
      case 2:
        printf("All Entries:\n"); 
        for(int i = 0; i < count; i++) { // Loop through all entries made so far
          printf("Date: %s\n", diary[i].date);
          printf("Title: %s\n", diary[i].title);
          printf("Content: %s\n\n", diary[i].content);
        }
        break;
      case 3:
        printf("Enter the title of the entry you want to edit: ");
        char title[100];
        scanf("%s", &title);
        for(int i = 0; i < count; i++) {
          if(strcmp(title, diary[i].title) == 0) { // Compare the title with each entry
            printf("Enter the new title: ");
            scanf("%s", &diary[i].title);
            printf("Enter the new content: ");
            scanf("%s", &diary[i].content);
            printf("Entry edited!\n\n");
            break;
          }
        }
        break;
      case 4:
        printf("Enter the title of the entry you want to delete: ");
        char del_title[100];
        scanf("%s", &del_title);
        for(int i = 0; i < count; i++) {
          if(strcmp(del_title, diary[i].title) == 0) {
            for(int j = i; j < count - 1; j++) { // Shift entries to fill deleted entry
              diary[j] = diary[j+1];
            }
            count--; // Decrement the counter variable
            printf("Entry deleted!\n\n");
            break;
          }
        }
        break;
      case 5:
        printf("Goodbye!\n");
        exit(0); // Terminate the program
      default:
        printf("Invalid option, please try again.\n");
        break;
    }
  }
  return 0;
}