//FormAI DATASET v1.0 Category: Digital Diary ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct diary_entry {
  char date[20];
  char time[20];
  char title[50];
  char body[500];
};

void clear_screen(){
  printf("\033[H\033[J");
}

void view_all_entries(struct diary_entry entries[], int N){
  clear_screen();
  printf("\t\t\t\t--- All Entries ---\n\n");
  for(int i=0; i<N; i++){
    printf("\t\t\t\t---- Entry %d ----\n", i+1);
    printf("Date: %s\n", entries[i].date);
    printf("Time: %s\n", entries[i].time);
    printf("Title: %s\n", entries[i].title);
    printf("Body:\n%s\n\n", entries[i].body);
  }
}

void add_new_entry(struct diary_entry entries[], int *N){
  clear_screen();
  printf("\t\t\t\t--- Add New Entry ---\n\n");
  struct diary_entry new_entry;
  printf("Enter The Date(YYYY-MM-DD):\n");
  scanf("%s", new_entry.date);
  printf("Enter The Time(HH:MM AM/PM):\n");
  scanf("%s", new_entry.time);
  printf("Enter The Title:\n");
  scanf("%s", new_entry.title);
  printf("Enter The Body(Max 500 Words):\n");
  scanf("%s", new_entry.body);
  strcat(new_entry.body, "\n");
  fgets(new_entry.body+strlen(new_entry.body), 500-strlen(new_entry.body), stdin);
  entries[*N] = new_entry;
  (*N)++;
}

void search_by_date(struct diary_entry entries[], int N){
  clear_screen();
  printf("\t\t\t\t--- Search By Date ---\n\n");
  char search_date[20];
  printf("Enter The Date To Search(YYYY-MM-DD):\n");
  scanf("%s", search_date);
  int found = 0;
  for(int i=0; i<N; i++){
    if(strcmp(search_date, entries[i].date) == 0){
      printf("Date: %s\n", entries[i].date);
      printf("Time: %s\n", entries[i].time);
      printf("Title: %s\n", entries[i].title);
      printf("Body:\n%s\n\n", entries[i].body);
      found = 1;
    }
  }
  if(found == 0){
    printf("Sorry, No Entries Found For The Given Date.\n\n");
  }
}

void search_by_title(struct diary_entry entries[], int N){
  clear_screen();
  printf("\t\t\t\t--- Search By Title ---\n\n");
  char search_title[50];
  printf("Enter The Title To Search:\n");
  scanf("%s", search_title);
  int found = 0;
  for(int i=0; i<N; i++){
    if(strcmp(search_title, entries[i].title) == 0){
      printf("Date: %s\n", entries[i].date);
      printf("Time: %s\n", entries[i].time);
      printf("Title: %s\n", entries[i].title);
      printf("Body:\n%s\n\n", entries[i].body);
      found = 1;
    }
  }
  if(found == 0){
    printf("Sorry, No Entries Found For The Given Title.\n\n");
  }
}

int main() {
  clear_screen();
  printf("\t\t\t\t--- C Digital Diary ---\n\n");
  int N = 0, choice;
  struct diary_entry entries[100];

  while(1){
    printf("Select An Option:\n");
    printf("1. View All Entries\n");
    printf("2. Add New Entry\n");
    printf("3. Search By Date\n");
    printf("4. Search By Title\n");
    printf("5. Quit\n");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        view_all_entries(entries, N);
        break;
      case 2:
        add_new_entry(entries, &N);
        break;
      case 3:
        search_by_date(entries, N);
        break;
      case 4:
        search_by_title(entries, N);
        break;
      case 5:
        clear_screen();
        printf("Quitting Digital Diary...\n");
        exit(0);
      default:
        printf("Invalid Choice, Try Again...\n");
    }
  }

  return 0;
}