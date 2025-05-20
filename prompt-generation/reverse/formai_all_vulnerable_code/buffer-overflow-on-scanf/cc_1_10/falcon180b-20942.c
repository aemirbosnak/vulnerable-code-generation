//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 10
#define SIZE1 20

struct movie{
    char title[SIZE];
    char director[SIZE];
    char actors[SIZE1][SIZE];
    int rating;
    int count;
};

void addmovie(struct movie *movies, int n){
    printf("Enter movie title: ");
    scanf("%s",movies[n].title);
    printf("Enter movie director: ");
    scanf("%s",movies[n].director);
    printf("Enter number of actors: ");
    scanf("%d",&movies[n].count);
    for(int i=0;i<movies[n].count;i++){
        printf("Enter actor %d name: ",i+1);
        scanf("%s",movies[n].actors[i]);
    }
    printf("Enter movie rating: ");
    scanf("%d",&movies[n].rating);
}

void displaymovies(struct movie movies[], int n){
    printf("Movie Title\t\tDirector\t\tActors\t\tRating\n");
    for(int i=0;i<n;i++){
        printf("%s\t\t%s\t\t",movies[i].title,movies[i].director);
        for(int j=0;j<movies[i].count;j++){
            printf("%s\t\t",movies[i].actors[j]);
        }
        printf("%d\n",movies[i].rating);
    }
}

int main(){
    struct movie movies[SIZE];
    int n;
    printf("Enter number of movies: ");
    scanf("%d",&n);
    printf("Enter movie details:\n");
    for(int i=0;i<n;i++){
        addmovie(movies,i);
    }
    printf("Movie details entered successfully!\n");
    displaymovies(movies,n);
    return 0;
}