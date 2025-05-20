//FormAI DATASET v1.0 Category: Movie Rating System ; Style: surrealist
#include <stdio.h> 
#include <stdlib.h>
#define MAX_RATINGS 1000

void print_grade(int rating){
        printf("\n");
        if(rating > 0 && rating < 4){
            printf("This film may cause severe headaches. Viewer discretion is advised.\n");
        }else if(rating == 4){
            printf("This film will leave you scratching your head for days to come. Proceed with caution.\n");
        }else if(rating == 5){
            printf("A masterpiece of surrealist cinema. One of the greatest films ever made.\n");
        }else{
            printf("An unremarkable movie. You may want to consider watching something else instead.\n");
        }
}

int main(){
    int n, i, rating, total = 0;
    double average;

    printf("Welcome to our unique C Movie Rating System!\n");
    printf("Please enter the number of ratings you want to give: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("Invalid input. Exiting...\n");
        return 0;
    }

    printf("Please give your ratings (from 1 to 5):\n");

    int ratings[MAX_RATINGS];
    for(i = 0; i < n; i++){
        printf("Rating #%d: ", i+1);
        scanf("%d", &rating);

        if(rating < 1 || rating > 5){
            printf("Invalid rating. Skipping...\n");
            continue;
        }

        ratings[total] = rating;
        total++;

        print_grade(rating);
    }

    if(total == 0){
        printf("No valid ratings submitted. Exiting...\n");
        return 0;
    }

    printf("\nThank you for your feedback!\n");

    average = (double)total / n * 100;
    printf("Percentage of valid ratings: %.2f%%\n", average);

    printf("List of Ratings: ");
    for(i = 0; i < total; i++){
        printf("%d ", ratings[i]);
    }

    printf("\n");
    return 0;
}