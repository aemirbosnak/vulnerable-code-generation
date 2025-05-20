//FormAI DATASET v1.0 Category: Digital Diary ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Function prototypes
void addEntry();
void searchEntry();
void displayAllEntries();
void displayMenu();

//Structure for Diary entry
struct entry{
  char date[12];
  char time[10];
  char description[500];
};

//Global variables
int numEntries = 0;
struct entry *entryList = NULL;

int main(){

  //Display welcome message
  printf("\nWelcome to your Digital Diary!\n");

  int choice;

  do{

    //Display main menu and get user input
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    //Switch statement to perform appropriate function based on user choice
    switch(choice){
      case 1:
        addEntry();
        break;
      case 2:
        searchEntry();
        break;
      case 3:
        displayAllEntries();
        break;
      case 4:
        printf("\nGoodbye!\n");
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
    }

  }while(choice != 4);

  //Free dynamically allocated memory and exit program
  free(entryList);
  return 0;
}

void displayMenu(){
  //Display menu options
  printf("\nMenu\n");
  printf("1. Add entry\n");
  printf("2. Search entry\n");
  printf("3. Display all entries\n");
  printf("4. Exit\n");
}

void addEntry(){

  //Create new Diary entry and increase total number of entries
  struct entry newEntry;
  numEntries++;

  //Allocate memory for additional entry into existing entryList
  struct entry *newEntryList = (struct entry*) realloc(entryList, numEntries * sizeof(struct entry));
  entryList = newEntryList;

  //Get user input for date, time and description of the new entry
  printf("\nEnter date (dd/mm/yyyy): ");
  scanf("%s", newEntry.date);
  printf("Enter time (hh:mm): ");
  scanf("%s", newEntry.time);
  printf("Enter description (500 chars max):\n");
  getchar();
  fgets(newEntry.description, sizeof(newEntry.description), stdin);

  //Add new entry to entryList and update file
  entryList[numEntries - 1] = newEntry;

  printf("\nEntry added!\n");
}

void searchEntry(){

  //Get user input for date to be searched
  char searchDate[12];
  printf("\nEnter date to search (dd/mm/yyyy): ");
  scanf("%s", searchDate);

  int found = 0;

  //Iterate over all entries and print matching entry
  for(int i = 0; i < numEntries; i++){
    if(strcmp(entryList[i].date, searchDate) == 0){
      found = 1;
      printf("\nDate: %s\n", entryList[i].date);
      printf("Time: %s\n", entryList[i].time);
      printf("Description: %s\n", entryList[i].description);
      break;
    }
  }

  if(!found){
    printf("\nNo entry found for the given date.\n");
  }
}

void displayAllEntries(){
  //Iterate over all entries and print each entry
  for(int i = 0; i < numEntries; i++){
    printf("\nDate: %s\n", entryList[i].date);
    printf("Time: %s\n", entryList[i].time);
    printf("Description: %s\n", entryList[i].description);
  }
}