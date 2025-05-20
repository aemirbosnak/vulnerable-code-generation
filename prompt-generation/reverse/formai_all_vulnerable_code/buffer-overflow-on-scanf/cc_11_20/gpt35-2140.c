//FormAI DATASET v1.0 Category: Database simulation ; Style: funny
#include<stdio.h>
#include<string.h>
//the Pet Database
struct pet { 
  char name[30];
  int age;
  float weight;
  char breed[50];
} pets[100];
int main(){
  int i=0, choice, n=0;
  printf("PET DATABASE SIMULATOR\n");
  while(1){
    printf("\nWhat would you like to do?\n");
    printf("1. Add a pet\n2. Remove a pet\n3. View all pets\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: 
        printf("\nEnter the details of the pet:\n");
        printf("Name: ");
        scanf("%s", pets[i].name);
        printf("Age: ");
        scanf("%d", &pets[i].age);
        printf("Weight: ");
        scanf("%f", &pets[i].weight);
        printf("Breed: ");
        scanf("%s", pets[i].breed);
        printf("Added %s to the pet database!\n", pets[i].name);
        i++;
        n++;
        break;
      case 2:
        if(n==0){
          printf("\nNo pets in the database to remove!\n");
          break;
        }
        char del[30];
        printf("\nEnter the name of the pet to remove: ");
        scanf("%s",del);
        for(int j=0;j<i;j++){
          if(strcmp(pets[j].name, del) == 0){
            for(int k=j; k<=i-2; k++){
              strcpy(pets[k].name, pets[k+1].name);
              pets[k].age = pets[k+1].age;
              pets[k].weight = pets[k+1].weight;
              strcpy(pets[k].breed, pets[k+1].breed);
            }
            i--;
            n--;
            printf("\n%s was removed from the pet database!\n",del);
            break;
          }
          if(j==i-1)
            printf("\n%s not found in the database, sorry!\n",del);
        }
        break;
      case 3:
        if(n==0){
          printf("\nNo pets in the database to view!\n");
          break;
        }
        printf("\nList of pets in the database:\n");
        for(int j=0;j<i;j++){
          printf("%d) Name: %s, Age: %d, Weight: %.2f, Breed: %s\n", j+1, pets[j].name, pets[j].age, pets[j].weight, pets[j].breed);
        }
        break;
      case 4:
        printf("\nGoodbye! Thank you for using the Pet Database Simulator!\n");
        return 0;
      default:
        printf("\nInvalid choice, please try again!\n");
    }
  }
}