//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book{
    char title[50];
    int id;
    int pages;
};

struct music{
    char title[50];
    int id;
    char composer[50];
    int length;
};

void search(struct music *music, int id)
{
    int i;
    for(i=0; i<music->id; i++){
        if(music->id == id){
            printf("Title: %s\nComposer: %s\nLength: %d\n", music->title, music->composer, music->length);
        }
    }
}

void display(struct music *music, int id)
{
    int i;
    for(i=0; i<music->id; i++){
        if(music->id == id){
            printf("Title: %s\nComposer: %s\nLength: %d\n", music->title, music->composer, music->length);
        }
    }
}

int main()
{
    int choice, id;
    struct music *music;

    do
    {
        printf("\nDecentralized Music Library Management System\n");
        printf("1. Add Music\n");
        printf("2. Delete Music\n");
        printf("3. Search Music\n");
        printf("4. Display Music\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the title: ");
                scanf("%s", &music->title);
                printf("Enter the composer: ");
                scanf("%s", &music->composer);
                printf("Enter the length: ");
                scanf("%d", &music->length);
                printf("Enter the ID: ");
                scanf("%d", &id);
                music->id = id;
                printf("Music added successfully.\n");
                break;
            case 2:
                printf("Enter the ID: ");
                scanf("%d", &id);
                search(music, id);
                break;
            case 3:
                printf("Enter the ID: ");
                scanf("%d", &id);
                display(music, id);
                break;
            case 4:
                display(music, id);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice!=5);

    return 0;
}