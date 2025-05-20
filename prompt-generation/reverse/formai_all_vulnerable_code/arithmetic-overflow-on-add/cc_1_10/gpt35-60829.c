//FormAI DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void writeData(FILE *fileptr);
void readData(FILE *fileptr);

int main()
{
  FILE *filePointer;
  int actionChoice, loop = 1;

  while (loop == 1)
  {
    printf("\nWelcome to your Digital Diary!\n");
    printf("What would you like to do?\n");
    printf("[1] Write something new\n");
    printf("[2] Read previous entries\n");
    printf("[3] Exit program\n");
    printf("Enter your choice: ");
    scanf("%d", &actionChoice);

    switch (actionChoice)
    {
      case 1:
        filePointer = fopen("digitalDiary.txt", "a");
        if (filePointer == NULL)
        {
          printf("Error opening file.\n");
          exit(1);
        }
        writeData(filePointer);
        fclose(filePointer);
        break;
      case 2:
        filePointer = fopen("digitalDiary.txt", "r");
        if (filePointer == NULL)
        {
          printf("Error opening file.\n");
          exit(1);
        }
        readData(filePointer);
        fclose(filePointer);
        break;
      case 3:
        loop = 0;
        printf("Bye bye!\n");
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  }
}

void writeData(FILE *filePtr)
{
  char entry[300];
  time_t now;
  struct tm *timeInfo;
  
  printf("Type your entry (Max 300 characters): ");
  fflush(stdin);
  fgets(entry, 300, stdin);
  time(&now);
  timeInfo = localtime(&now);

  fprintf(filePtr, "Entry Date: %02d/%02d/%04d at %02d:%02d\n",
    timeInfo->tm_mday, timeInfo->tm_mon+1, timeInfo->tm_year+1900, 
    timeInfo->tm_hour, timeInfo->tm_min);
  fprintf(filePtr, "%s\n", entry);
  printf("Entry saved successfully!\n");
}

void readData(FILE *filePtr)
{
  char line[500];
  while (fgets(line, 500, filePtr) != NULL)
    printf("%s", line);
}