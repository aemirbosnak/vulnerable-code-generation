//FormAI DATASET v1.0 Category: Data mining ; Style: funny
#include <stdio.h> 

int main() 
{ 
    printf("Welcome to the Data Mining Adventures with 'Little Jimmy'!\n\n"); 

    // First, let's collect some data regarding Jimmy's favorite foods 
    char pizza[] = "Pizza"; 
    char hamburger[] = "Hamburger"; 
    char sushi[] = "Sushi"; 

    printf("Little Jimmy, how much do you like pizza? (1 - Not at all, 10 - Love it!) > "); 
    int pizza_rating; 
    scanf("%d", &pizza_rating); 

    printf("What about hamburgers? (1 - Not at all, 10 - Love it!) > "); 
    int hamburger_rating; 
    scanf("%d", &hamburger_rating); 

    printf("And finally, how do you feel about sushi? (1 - Not at all, 10 - Love it!) > "); 
    int sushi_rating; 
    scanf("%d", &sushi_rating); 

    // Now that we have the data, let's analyze it! 
    if (pizza_rating > 5 && hamburger_rating > 5 && sushi_rating > 5) 
    { 
        printf("\nWow, Little Jimmy is a foodie! He loves all three foods equally.\n"); 
    } 
    else if (pizza_rating > hamburger_rating && pizza_rating > sushi_rating) 
    { 
        printf("\nLooks like Little Jimmy has a soft spot for pizza! It's his favorite food.\n"); 
    } 
    else if (hamburger_rating > pizza_rating && hamburger_rating > sushi_rating) 
    { 
        printf("\nLittle Jimmy loves burgers more than anything else! They're his favorite food.\n"); 
    } 
    else if (sushi_rating > pizza_rating && sushi_rating > hamburger_rating) 
    { 
        printf("\nSushi is Little Jimmy's favorite food! He loves it more than anything else.\n"); 
    } 
    else if (pizza_rating == hamburger_rating || pizza_rating == sushi_rating || hamburger_rating == sushi_rating) 
    { 
        printf("\nLittle Jimmy is indecisive, he loves two of the three foods equally.\n"); 
    } 
    else 
    { 
        printf("\nHmm, it seems like Little Jimmy doesn't really like any of these foods.\n"); 
    } 

    printf("\nThanks for joining us on this data mining adventure with Little Jimmy!\n"); 

    return 0; 
}