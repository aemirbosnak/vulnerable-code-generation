//FormAI DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

struct MailingList{
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

int main(){
    printf("Welcome to the Mailing List Manager!\n");
    printf("Enter the number of people you want to add in the mailing list: ");

    int numOfPeople;
    scanf("%d", &numOfPeople);

    struct MailingList *list = malloc(numOfPeople * sizeof(struct MailingList));
    
    printf("Enter the details of %d people:\n", numOfPeople);

    for(int i=0; i<numOfPeople; i++){
        printf("Person %d Name: ", i+1);
        scanf("%s", list[i].name);
        printf("Person %d Email: ", i+1);
        scanf("%s", list[i].email);
        printf("\n");
    }

    printf("Mailing List:\n");

    for(int i=0; i<numOfPeople; i++){
        printf("%s, %s\n", list[i].name, list[i].email);
    }

    printf("\nEnter the name of the person you want to remove: ");
    
    char nameToRemove[MAX_NAME_LENGTH];
    scanf("%s", nameToRemove);

    for(int i=0; i<numOfPeople; i++){
        if(strcmp(list[i].name, nameToRemove) == 0){
            for(int j=i; j<numOfPeople-1; j++){
                strcpy(list[j].name, list[j+1].name);
                strcpy(list[j].email, list[j+1].email);
            }
            numOfPeople--;
            break;
        }
    }

    printf("\nUpdated Mailing List:\n");

    for(int i=0; i<numOfPeople; i++){
        printf("%s, %s\n", list[i].name, list[i].email);
    }

    free(list);
    return 0;
}