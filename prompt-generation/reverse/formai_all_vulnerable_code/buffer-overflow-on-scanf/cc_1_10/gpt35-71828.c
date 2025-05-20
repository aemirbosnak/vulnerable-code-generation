//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define a structure to hold the record of a person in the database
struct Person{
    char name[50];
    int age;
    char phone[15];
    char email[50];
};

//define a function to insert a new person record into the database
void insert(struct Person *p, int *numRecords){
    printf("\nEnter Name: ");
    scanf("%s", p[*numRecords].name);
    printf("Enter Age: ");
    scanf("%d", &p[*numRecords].age);
    printf("Enter Phone Number: ");
    scanf("%s", p[*numRecords].phone);
    printf("Enter Email: ");
    scanf("%s", p[*numRecords].email);
    (*numRecords)++;
    printf("\nRecord added successfully!\n");
}

//define a function to search for a person record in the database
void search(struct Person *p, int numRecords){
    char name[50];
    printf("\nEnter Name to search for: ");
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<numRecords; i++){
        if(strcmp(p[i].name, name)==0){
            printf("\nRecord Found!\nName: %s\nAge: %d\nPhone: %s\nEmail: %s\n", p[i].name, p[i].age, p[i].phone, p[i].email);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("\nRecord not found!\n");
    }
}

//define a function to display all person records in the database
void display(struct Person *p, int numRecords){
    printf("\nAll Records:\n");
    for(int i=0; i<numRecords; i++){
        printf("Name: %s\nAge: %d\nPhone: %s\nEmail: %s\n\n", p[i].name, p[i].age, p[i].phone, p[i].email);
    }
}

int main(){
    struct Person people[100];
    int numRecords = 0;
    int choice = 0;
    while(choice!=4){
        printf("\n\n1. Insert new record\n2. Search for a record\n3. Display All Records\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert(people, &numRecords);
                break;
            case 2:
                search(people, numRecords);
                break;
            case 3:
                display(people, numRecords);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice, try again!\n");
                break;
        }
    }
    return 0;
}