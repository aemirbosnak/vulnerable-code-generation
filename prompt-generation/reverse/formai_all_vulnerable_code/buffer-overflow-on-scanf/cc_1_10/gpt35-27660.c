//FormAI DATASET v1.0 Category: Digital Diary ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct diary_entry
{
  int day;
  int month;
  int year;
  char entry[500];
};

int main()
{
  int choice, count = 0;
  struct diary_entry entries[365];
  printf("Welcome to my digital diary! \n\n");

  while(1)
  {
    printf("Choose an option: \n");
    printf("1. Add entry \n");
    printf("2. View entries \n");
    printf("3. Exit \n");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
      {
        if(count < 365)
        {
          printf("Enter the date (DD MM YYYY): ");
          scanf("%d %d %d", &entries[count].day, &entries[count].month, &entries[count].year);

          printf("Enter your entry: \n");
          fflush(stdin);
          fgets(entries[count].entry, sizeof(entries[count].entry), stdin);

          count++;
        }
        else
        {
          printf("\nSorry, the diary is full!");
        }
        break;
      }
      case 2:
      {
        if(count == 0)
        {
          printf("\nThere are no entries yet.");
        }
        else
        {
          printf("\nHere are your entries: \n");
          for(int i=0;i<count;i++)
          {
            printf("\nEntry %d: \n", i+1);
            printf("%d/%d/%d: \n", entries[i].day, entries[i].month, entries[i].year);
            printf("%s", entries[i].entry);
          }
        }
        break;
      }
      case 3:
        printf("\nGoodbye!");
        exit(0);
        break;
      default:
        printf("\nInvalid choice. Please try again.");
        break;
    }
  }

  return 0;
}