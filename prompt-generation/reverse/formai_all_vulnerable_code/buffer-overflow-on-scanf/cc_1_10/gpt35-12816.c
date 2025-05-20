//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
    int score=0;
    char answer[20];
    srand(time(0));
    printf("Welcome to the Periodic Table Quiz. \n");
    printf("Please enter the correct symbol for each element given. \n");
    printf("Press 'h' for hint and 's' to skip to the next question. \n");
    printf("Let's begin! \n\n");

    // array of element symbols
    char *elements[]={"H","He","Li","Be","B","C","N",
                    "O","F","Ne","Na","Mg","Al","Si",
                    "P","S","Cl","Ar","K","Ca"};

    // corresponding array of element names
    char *names[]={"Hydrogen","Helium","Lithium","Beryllium",
                    "Boron","Carbon","Nitrogen","Oxygen",
                    "Fluorine","Neon","Sodium","Magnesium",
                    "Aluminum","Silicon","Phosphorus",
                    "Sulfur","Chlorine","Argon","Potassium","Calcium"};

    int n = sizeof(elements)/sizeof(elements[0]);

    for(int i=0;i<10;i++){
        int random_index = rand()%n;
        char *element_symbol = elements[random_index];

        printf("What is the symbol for element %s? ",names[random_index]);
        scanf("%s",answer);

        if(strcmp(answer,element_symbol)==0){
            printf("Correct! +10 points\n\n");
            score += 10;
        }
        else if(strcmp(answer,"h")==0){
            printf("Hint: The first letter of the symbol is %c\n",element_symbol[0]);
            i--;
        }
        else if(strcmp(answer,"s")==0){
            printf("Skipping to the next question\n\n");
            i--;
        }
        else{
            printf("Incorrect. The correct symbol for %s is %s\n\n",names[random_index],element_symbol);
        }
    }
    printf("Your score is %d\n",score);
    return 0;
}