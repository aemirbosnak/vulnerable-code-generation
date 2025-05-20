//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int probability, aliens, countries, i, j, k;
    float total_prob, avg_prob;

    srand(time(NULL)); //initialize random seed using current time

    //get user input
    printf("Enter the number of countries: ");
    scanf("%d", &countries);
    printf("Enter the number of aliens: ");
    scanf("%d", &aliens);

    //initialize probability matrix
    int matrix [countries][aliens+1];
    for (i=0;i<countries;i++) {
        for (j=0;j<=aliens;j++) {
            matrix[i][j] = rand()%101;
            printf("%d ", matrix[i][j]); //print matrix for debugging purposes
        }
        printf("\n");
    }

    //calculate total probability of an invasion in each country
    for (i=0;i<countries;i++) {
        total_prob = 0;
        for (j=0;j<=aliens;j++) {
            probability = matrix[i][j];
            total_prob += probability/100.0; //convert probability to decimal and add to total
        }
        printf("Total probability of an invasion in Country %d: %.2f\n", i+1, total_prob);
    }

    //calculate average probability of an invasion across all countries
    avg_prob = 0;
    for (i=0;i<countries;i++) {
        total_prob = 0;
        for (j=0;j<=aliens;j++) {
            probability = matrix[i][j];
            total_prob += probability/100.0; //convert probability to decimal and add to total
        }
        avg_prob += total_prob;
    }
    avg_prob = avg_prob/countries;
    printf("Average probability of an invasion across all countries: %.2f\n", avg_prob);

    return 0;
}