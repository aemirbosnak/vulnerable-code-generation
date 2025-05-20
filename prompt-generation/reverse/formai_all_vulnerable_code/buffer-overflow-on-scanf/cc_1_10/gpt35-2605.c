//FormAI DATASET v1.0 Category: Music Library Management System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct music{
    char name[30];
    char artist[30];
    char genre[20];
};

int size = 0;
struct music m[100];

void addMusic(){
    printf("Enter music name : ");
    scanf("%s", m[size].name);
    printf("Enter artist name : ");
    scanf("%s", m[size].artist);
    printf("Enter genre : ");
    scanf("%s", m[size].genre);
    printf("Music added successfully!\n\n");
    size++;
}

void searchMusic(){
    char name[30];
    printf("Enter music name : ");
    scanf("%s", name);
    for(int i=0; i<size; i++){
        if(strcmp(name, m[i].name)==0){
            printf("Music Found!\n");
            printf("Music name : %s\n", m[i].name);
            printf("Artist name : %s\n", m[i].artist);
            printf("Genre : %s\n", m[i].genre);
            return;
        }
    }
    printf("Music not found!\n");
}

void listMusic(){
    printf("\nList of all music : \n\n");
    for(int i=0; i<size; i++){
        printf("%d) %s by %s (%s)\n", i+1, m[i].name, m[i].artist, m[i].genre);
    }
    printf("\n");
}

int main(){
    int choice;
    printf("Welcome to the Music Library Management System!\n\n");

    while(1){
        printf("Please Select an Option : \n");
        printf("1. Add Music\n");
        printf("2. Search Music\n");
        printf("3. List all Music\n");
        printf("4. Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                addMusic();
                break;
            case 2:
                searchMusic();
                break;
            case 3:
                listMusic();
                break;
            case 4:
                printf("Thank you for using Music Library Management System!\n");
                exit(0);
            default:
                printf("Invalid choice, Please try again!\n\n");
                break;
        }
    }

    return 0;
}