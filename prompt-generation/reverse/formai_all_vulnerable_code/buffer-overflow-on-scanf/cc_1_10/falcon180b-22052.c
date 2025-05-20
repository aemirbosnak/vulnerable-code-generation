//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct movie{
    char name[MAX];
    char director[MAX];
    int year;
    char genre[MAX];
    int rating;
    int votes;
};

struct movie movies[100];
int num_movies = 0;

void add_movie(){
    printf("Enter movie name: ");
    scanf("%s",movies[num_movies].name);
    printf("Enter movie director: ");
    scanf("%s",movies[num_movies].director);
    printf("Enter movie year: ");
    scanf("%d",&movies[num_movies].year);
    printf("Enter movie genre: ");
    scanf("%s",movies[num_movies].genre);
    printf("Enter movie rating: ");
    scanf("%d",&movies[num_movies].rating);
    printf("Enter number of votes: ");
    scanf("%d",&movies[num_movies].votes);
    num_movies++;
}

void display_movies(){
    printf("\n");
    printf("Movie Name\tDirector\tYear\tGenre\tRating\tVotes\n");
    for(int i=0;i<num_movies;i++){
        printf("%s\t%s\t%d\t%s\t%d\t%d\n",movies[i].name,movies[i].director,movies[i].year,movies[i].genre,movies[i].rating,movies[i].votes);
    }
}

int main(){
    printf("Movie Rating System\n");
    while(1){
        printf("\n");
        printf("1.Add Movie\n2.Display Movies\n3.Exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_movie();
                break;
            case 2:
                display_movies();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}