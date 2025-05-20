//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    printf("Welcome to the Surreal Genome Sequencing Simulator!\n\n");

    printf("Please enter a sequence length (minimum 10): ");
    int length = 0;
    scanf("%d", &length);

    if (length < 10){
        printf("\nYou have not entered a valid length. Exiting...\n");
        exit(1);
    }

    char nucleotides[4] = {'A', 'C', 'G', 'T'};
    int random_num;
    srand(time(NULL));

    printf("\nGenerating random sequence...\n\n");

    for (int i = 0; i < length; i++){
        random_num = rand() % 4;
        printf(" %c ", nucleotides[random_num]);
    }

    printf("\n\nMutation time! Please select a position to mutate (max %d): ", length);
    int mutate_index = 0;
    scanf("%d", &mutate_index);

    if (mutate_index > length || mutate_index < 1){
        printf("\nYou have not entered a valid index. Exiting...\n");
        exit(1);
    }

    printf("\nMutating position %d...\n\n", mutate_index);

    random_num = rand() % 4;
    nucleotides[random_num] = nucleotides[mutate_index-1];

    for (int i = 0; i < length; i++){
        if (i == mutate_index-1){
            printf(" %c ", nucleotides[random_num]);
        }
        else{
            random_num = rand() % 4;
            printf(" %c ", nucleotides[random_num]);
        }
    }

    printf("\n\nGenome sequencing complete! Thank you for using our simulator.\n");

    return 0;
}