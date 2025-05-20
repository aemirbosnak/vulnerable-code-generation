//FormAI DATASET v1.0 Category: Music Library Management System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct music
{
    char title[50];
    char artist[50];
    float duration;
    char genre[20];
};

int main()
{
    int n,choice;
    printf("How many songs do you want to add?\n");
    scanf("%d",&n);
    struct music m[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the details of song %d:\n",i+1);
        printf("Title: ");
        scanf("%s",m[i].title);
        printf("Artist: ");
        scanf("%s",m[i].artist);
        printf("Duration: ");
        scanf("%f",&m[i].duration);
        printf("Genre: ");
        scanf("%s",m[i].genre);
    }

    do
    {
        printf("\nMenu:\n1. Display all songs\n2. Sort by artist\n3. Search by genre\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nAll songs:\n");
                    for(int i=0;i<n;i++)
                    {
                        printf("Title: %s\n",m[i].title);
                        printf("Artist: %s\n",m[i].artist);
                        printf("Duration: %.2f mins\n",m[i].duration);
                        printf("Genre: %s\n\n",m[i].genre);
                    }
                    break;

            case 2: printf("\nSorted by artist:\n");
                    for(int i=0;i<n-1;i++)
                    {
                        for(int j=i+1;j<n;j++)
                        {
                            if(strcmp(m[i].artist,m[j].artist)>0)
                            {
                                struct music temp=m[i];
                                m[i]=m[j];
                                m[j]=temp;
                            }
                        }
                    }
                    for(int i=0;i<n;i++)
                    {
                        printf("Title: %s\n",m[i].title);
                        printf("Artist: %s\n",m[i].artist);
                        printf("Duration: %.2f mins\n",m[i].duration);
                        printf("Genre: %s\n\n",m[i].genre);
                    }
                    break;

            case 3: printf("\nEnter the genre to search: ");
                    char searchgenre[20];
                    scanf("%s",searchgenre);
                    printf("\nSongs with genre %s:\n",searchgenre);
                    for(int i=0;i<n;i++)
                    {
                        if(strcmp(m[i].genre,searchgenre)==0)
                        {
                            printf("Title: %s\n",m[i].title);
                            printf("Artist: %s\n",m[i].artist);
                            printf("Duration: %.2f mins\n",m[i].duration);
                            printf("Genre: %s\n\n",m[i].genre);
                        }
                    }
                    break;

            case 4: printf("\nExiting...Thank you!\n");
                    exit(0);

            default: printf("\nInvalid choice! Please try again.\n");
                     break;
        }
    }while(choice!=4);

    return 0;
}