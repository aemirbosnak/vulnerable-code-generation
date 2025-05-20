//FormAI DATASET v1.0 Category: Music Library Management System ; Style: brave
#include<stdio.h>
#include<string.h>
struct song{
  char title[50];
  char artist[50];
  int yearOfRelease;
  float duration;
};
typedef struct song Song;
Song s[100];
int curr_size = 0;

void add(){
  printf("\n--- Add a Song ---\n");
  printf("Enter the title of the song: ");
  scanf("%s", &s[curr_size].title);
  printf("Enter the artist of the song: ");
  scanf("%s", &s[curr_size].artist);
  printf("Enter the year of release of the song: ");
  scanf("%d", &s[curr_size].yearOfRelease);
  printf("Enter the duration of the song: ");
  scanf("%f", &s[curr_size].duration);
  curr_size++;
}

void display(){
  printf("\n--- Song List ---\n");
  if (curr_size == 0){
    printf("The music library is empty.\n");
    return;
  }
  for(int i = 0; i < curr_size; i++){
    printf("%d.\nTitle: %s\nArtist: %s\nYear of Release: %d\nDuration: %.2f minutes\n", i+1, s[i].title, s[i].artist, s[i].yearOfRelease, s[i].duration);
  }
}

void search(){
  printf("\n--- Search for a Song ---\n");
  char title[50];
  printf("Enter the title of the song you want to search for: ");
  scanf("%s", &title);
  int found = 0;
  for(int i = 0; i < curr_size; i++){
    if(strcmp(title, s[i].title) == 0){
      printf("\nTitle: %s\nArtist: %s\nYear of Release: %d\nDuration: %.2f minutes\n", s[i].title, s[i].artist, s[i].yearOfRelease, s[i].duration);
      found = 1;
      break;
    }
  }
  if(!found){
    printf("\nThe song was not found in the music library.\n");
  }
}

int main(){
  int choice;
  printf("Welcome to the C Music Library Management System by [Your Name Here].\n");
  do{
    printf("\n===== Menu =====\n");
    printf("1. Add a Song\n");
    printf("2. Display all Songs\n");
    printf("3. Search for a Song\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        add();
        break;
      case 2:
        display();
        break;
      case 3:
        search();
        break;
      case 4:
        printf("\nThank you for using the C Music Library Management System.\n");
        return 0;
      default:
        printf("\nInvalid input. Please enter a number from 1-4.\n");
    }
  }while(choice != 4);
  return 0;
}