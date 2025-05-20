//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: automated
#include<stdio.h>
#include<stdlib.h>

struct movie{
    char title[100];
    char rating[20];
    int year;
    double price;
};

void print_menu() {
    printf("1. Add movie\n");
    printf("2. List movies\n");
    printf("3. Search movies\n");
    printf("4. Delete movie\n");
    printf("5. Quit\n");
}

void add_movie() {
    struct movie movie;
    printf("Enter movie title: ");
    scanf("%s",movie.title);
    printf("Enter movie rating: ");
    scanf("%s",movie.rating);
    printf("Enter movie release year: ");
    scanf("%d",&movie.year);
    printf("Enter movie price: ");
    scanf("%lf",&movie.price);
    printf("Movie added successfully!\n");
}

void list_movies() {
    struct movie movies[100];
    int i,j;
    printf("Title\tRating\tYear\tPrice\n");
    for(i=0;i<10;i++){
        for(j=0;j<i;j++){
            if(strcmp(movies[i].title,movies[j].title)==0){
                printf("Movie with the same title already exists!\n");
                break;
            }
        }
        printf("%s\t%s\t%d\t%lf\n",movies[i].title,movies[i].rating,movies[i].year,movies[i].price);
    }
}

void search_movies() {
    struct movie movies[100];
    int i,j,flag;
    printf("Enter movie title: ");
    scanf("%s",movies[i].title);
    for(i=0;i<10;i++){
        for(j=0;j<i;j++){
            if(strcmp(movies[i].title,movies[j].title)==0){
                printf("Movie found!\n");
                break;
            }
        }
        if(j==i){
            printf("Movie not found!\n");
        }
    }
}

void delete_movie() {
    struct movie movies[100];
    int i,j,flag;
    printf("Enter movie title: ");
    scanf("%s",movies[i].title);
    for(i=0;i<10;i++){
        for(j=0;j<i;j++){
            if(strcmp(movies[i].title,movies[j].title)==0){
                printf("Movie deleted successfully!\n");
                break;
            }
        }
        if(j==i){
            printf("Movie not found!\n");
        }
    }
}

int main() {
    int choice;
    do {
        print_menu();
        scanf("%d",&choice);
        switch(choice) {
            case 1: add_movie();
                break;
            case 2: list_movies();
                break;
            case 3: search_movies();
                break;
            case 4: delete_movie();
                break;
            case 5: exit(0);
        }
    } while(choice!=5);
    return 0;
}