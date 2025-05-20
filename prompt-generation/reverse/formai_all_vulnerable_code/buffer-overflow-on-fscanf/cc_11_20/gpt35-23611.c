//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include<stdio.h>

struct Person{
  char name[50];
  int age;
};

int main(){
  int choice;
  printf("Enter 1 to add a new person\n");
  printf("Enter 2 to display all persons\n");
  printf("Enter 3 to search for a person\n");
  printf("Enter 4 to exit the program\n");

  do{
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice){

      //Adding a new person
      case 1:{
        FILE *fptr;
        fptr = fopen("people.txt","a+");

        struct Person p;

        printf("\nEnter name: ");
        fflush(stdin);
        gets(p.name);

        printf("Enter age: ");
        scanf("%d",&p.age);

        fprintf(fptr,"%s,%d\n",p.name,p.age);

        printf("%s added to file successfully!\n",p.name);
        fclose(fptr);
        break;
      }

      //Displaying all persons
      case 2:{
        FILE *fptr;
        fptr = fopen("people.txt","r");

        if(fptr == NULL){
          printf("File doesn't exist or cannot be opened!\n");
          break;
        }

        printf("\nList of all persons:\n");
        char ch = fgetc(fptr);

        while(ch != EOF){
          printf("%c",ch);
          ch = fgetc(fptr);
        }

        fclose(fptr);
        break;
      }

      //Searching for a person
      case 3:{
        FILE *fptr;
        fptr = fopen("people.txt","r");

        if(fptr == NULL){
          printf("File doesn't exist or cannot be opened!\n");
          break;
        }

        struct Person p;
        char search_name[50];
        int found = 0;

        fflush(stdin);
        printf("\nEnter name to search: ");
        gets(search_name);

        while(fscanf(fptr, "%[^,],%d\n", p.name, &p.age) != EOF){
          if(strcmp(search_name,p.name) == 0){
            printf("\nName: %s\n",p.name);
            printf("Age: %d\n",p.age);
            found = 1;
            break;
          }
        }

        if(found == 0){
          printf("\n%s not found in file!\n",search_name);
        }

        fclose(fptr);
        break;
      }

      //Exiting the program
      case 4:{
        printf("\nExiting the program...\n");
        break;
      }

      //Invalid choice
      default:{
        printf("\nInvalid choice!\n");
        break;
      }
    }
  }while(choice != 4);

  return 0;
}