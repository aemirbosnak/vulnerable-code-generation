//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MOVIES 100
#define MAX_NAME 50
#define MAX_RATING 10

struct movie{
    char name[MAX_NAME];
    int rating;
};

struct movie movies[MAX_MOVIES];
int num_movies;

void add_movie(){
    char name[MAX_NAME];
    int rating;

    printf("Enter movie name: ");
    scanf("%s",name);

    printf("Enter movie rating: ");
    scanf("%d",&rating);

    strcpy(movies[num_movies].name,name);
    movies[num_movies].rating=rating;

    num_movies++;
}

void display_movies(){
    int i;

    printf("\nMovie Ratings:\n");
    printf("--------------------\n");

    for(i=0;i<num_movies;i++){
        printf("%s - %d\n",movies[i].name,movies[i].rating);
    }
}

void search_movie(){
    char name[MAX_NAME];
    int i;

    printf("Enter movie name to search: ");
    scanf("%s",name);

    for(i=0;i<num_movies;i++){
        if(strcmp(movies[i].name,name)==0){
            printf("\n%s - %d\n",movies[i].name,movies[i].rating);
        }
    }
}

void delete_movie(){
    char name[MAX_NAME];
    int i;

    printf("Enter movie name to delete: ");
    scanf("%s",name);

    for(i=0;i<num_movies;i++){
        if(strcmp(movies[i].name,name)==0){
            strcpy(movies[i].name," ");
            movies[i].rating=0;
        }
    }
}

int main(){
    int choice;

    printf("Welcome to the Post-Apocalyptic Movie Rating System\n");
    printf("---------------------------------------------\n");

    do{
        printf("\n1. Add Movie\n2. Display Movies\n3. Search Movie\n4. Delete Movie\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                add_movie();
                break;

            case 2:
                display_movies();
                break;

            case 3:
                search_movie();
                break;

            case 4:
                delete_movie();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=5);

    return 0;
}