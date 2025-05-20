//FormAI DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct PhoneBook{
    char name[20];
    char number[15];
};

struct PhoneBook book[100];
int p_count = 0;

void addEntry(){
    printf("Enter Name:\n");
    scanf("%s",(book+p_count)->name);
    getchar();
    printf("Enter Phone Number:\n");
    scanf("%s",(book+p_count)->number);
    getchar();
    printf("Entry added successfully!\n\n");
    p_count++;
}

void printEntries(){
    if(p_count == 0){
        printf("No entries found.\n\n");
    }else{
        printf("Phone Book:\n\n");
        for(int i=0;i<p_count;i++){
            printf("%d. Name: %s\n   Number: %s\n\n",i+1,(book+i)->name,(book+i)->number);
        }
    }
}

void searchEntry(){
    char search_name[20];
    int found = 0;
    printf("Enter Name to search:\n");
    scanf("%s",search_name);
    getchar();
    printf("searching...\n\n");
    for(int i=0;i<p_count;i++){
        if(strcmp((book+i)->name,search_name) == 0){
            found = 1;
            printf("Name found!\n   Name: %s\n   Number: %s\n\n",(book+i)->name,(book+i)->number);
        }
    }
    if(found == 0){
        printf("Name not found.\n\n");
    }
}

int main(){
    int choice;
    printf("\n***Welcome to Phone Book!***\n\n");
    do{
        printf("\n1. Add new entry.\n");
        printf("2. Print all entries.\n");
        printf("3. Search an entry.\n");
        printf("4. Exit.\n\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1: addEntry();
                    break;
            case 2: printEntries();
                    break;
            case 3: searchEntry();
                    break;
            case 4: printf("Thank you for using Phone Book.\n\n");
                    break;
            default: printf("Invalid choice!\n\n");
                     break;
        }
    }while(choice != 4);
    return 0;
}