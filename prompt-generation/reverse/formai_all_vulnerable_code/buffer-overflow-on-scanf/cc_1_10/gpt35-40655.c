//FormAI DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to The Rock's Music Library Manager\n");
  
  printf("*********************************\n");
  printf("*   Menu                        *\n");
  printf("*     1. Add Song               *\n");
  printf("*     2. Remove Song            *\n");
  printf("*     3. List All Songs         *\n");
  printf("*     4. Shuffle Play           *\n");
  printf("*     5. Quit                   *\n");
  printf("*********************************\n");
  
  int menuChoice, numSongs = 0, i;
  char songName[50], artist[50], album[50], genre[50];
  
  do {
    printf("Enter choice (1-5): ");
    scanf("%d", &menuChoice);
  
    switch(menuChoice) {
      
      case 1:
        printf("Enter song name: ");
        scanf("%s", songName);
        
        printf("Enter artist: ");
        scanf("%s", artist);
        
        printf("Enter album: ");
        scanf("%s", album);
        
        printf("Enter genre: ");
        scanf("%s", genre);
        
        printf("'%s' by %s added to library.\n", songName, artist);
        numSongs++;
        break;
      
      case 2:
        printf("Enter the number of the song to be removed: ");
        scanf("%d", &i);
        if (i <= numSongs) {
          printf("Song '%s' by %s removed.\n", songName, artist);
          numSongs--;
        }
        else {
          printf("Error: Song not found.\n");
        }
        break;
      
      case 3:
        printf("Total Songs: %d\n\n", numSongs);
        // Code to display all songs in the library
        break;
      
      case 4:
        printf("Shuffling...\n");
        // Code to play shuffled library
        break;
      
      case 5:
        printf("Goodbye!\n");
        break;
      
      default:
        printf("Error: Invalid choice.\n");
        break;
    }
  
  } while(menuChoice != 5);
  
  return 0;
}