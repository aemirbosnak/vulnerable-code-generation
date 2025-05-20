//FormAI DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include<stdio.h>

struct diary{           //defining the diary structure
  int date, month, year;
  char description[50];
};

void main(){

  struct diary d[100];  //creating an array of structure diary

  int n, choice;
  printf("Enter the number of entries you want to add: ");
  scanf("%d", &n);

  for(int i=0; i<n; i++){   //loop to enter diary entries
    printf("\nEnter the date(mm/dd/yyyy format) for entry %d: ", i+1);
    scanf("%d/%d/%d", &d[i].month, &d[i].date, &d[i].year);
    printf("Enter the description for the entry %d: ", i+1);
    scanf(" %[^\n]", d[i].description);
  }

  printf("\n--------DIARY ENTRIES--------\n");

  for(int i=0; i<n; i++){   //loop to display the diary entries
    printf("\n%d/%d/%d\n", d[i].month, d[i].date, d[i].year);
    printf("%s", d[i].description);
    printf("\n\n");
  }

  while(1){  
    printf("\nSelect an option: \n1. Add entry \n2. Delete entry \n3. Exit\n"); //menu displayed for user options
    scanf("%d", &choice);

    if(choice==1){   //condition for adding entries
      printf("\nEnter the date(mm/dd/yyyy format) for entry: ");
      scanf("%d/%d/%d", &d[n].month, &d[n].date, &d[n].year);
      printf("Enter the description for the entry: ");
      scanf(" %[^\n]", d[n].description);
      n++;
    }

    else if(choice==2){  //condition to delete an entry
      int del;
      printf("\nEnter the number of entry you want to delete: ");
      scanf("%d", &del);
      for(int i=del; i<n; i++){
        d[i-1]=d[i];
      }
      n--;
    }

    else{
      break;    //terminates the while loop
    }

    printf("\n--------DIARY ENTRIES--------\n");

    for(int i=0; i<n; i++){   //displaying all entries after adding or deleting
      printf("\n%d/%d/%d\n", d[i].month, d[i].date, d[i].year);
      printf("%s", d[i].description);
      printf("\n\n");
    }

  }

}