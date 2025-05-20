//FormAI DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

struct Entry {
   char date[20];
   char time[10];
   char content[200];
};

void addEntry(struct Entry *d) {
   printf("\nEnter Date (MM/DD/YYYY): ");
   scanf("%s", d->date);
   printf("Enter Time (hh:mm): ");
   scanf("%s", d->time);

   printf("Enter content:\n");
   getchar();
   fgets(d->content, 200, stdin);
}

void displayEntry(struct Entry d) {
   printf("\nDate: %s\n", d.date);
   printf("Time: %s\n", d.time);
   printf("Content: %s\n", d.content);
}

int main() {
   struct Entry diary[1000];
   int choice, numEntries=0, i;

   do {
      // show options
      printf("\nDigital Diary Options:\n");
      printf("1. Add entry\n");
      printf("2. View all entries\n");
      printf("3. Exit\n");
      
      //ask for choice 
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            // add entry
            addEntry(&diary[numEntries]);
            numEntries++;
            break;
         case 2:
            // display all entries
            for(i=0; i<numEntries; i++) {
               displayEntry(diary[i]);
            }
            break;
         case 3:
            // exit
            printf("Goodbye!\n");
            break;
         default:
            printf("Invalid choice. Please try again.\n");
            break;
      }

   } while(choice != 3);

   return 0;
}