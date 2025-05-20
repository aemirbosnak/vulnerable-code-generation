//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Cryptic
#include <stdio.h>
 
int main() {
    printf("Welcome to the Cryptic Periodic Table Quiz!\n");
    printf("Can you guess the elements from their atomic numbers?\n");
    printf("Ready? Let's begin!\n\n");
    
    int score = 0;
    int answer;
    
    printf("1. This element has the atomic number 6. ");
    scanf("%d", &answer);
    if (answer == 6) {
        printf("Correct!\n");
        score += 10;
    } else {
        printf("Incorrect.\n");
    }
    
    printf("2. This element has the atomic number 26 and is known for its magnetic properties. ");
    scanf("%d", &answer);
    if (answer == 26) {
        printf("Correct!\n");
        score += 10;
    } else {
        printf("Incorrect.\n");
    }
    
    printf("3. This element has the atomic number 29 and is commonly used in electrical wiring. ");
    scanf("%d", &answer);
    if (answer == 29) {
        printf("Correct!\n");
        score += 10;
    } else {
        printf("Incorrect.\n");
    }
    
    printf("4. This element has the atomic number 47 and is used in jewellery. ");
    scanf("%d", &answer);
    if (answer == 47) {
        printf("Correct!\n");
        score += 10;
    } else {
        printf("Incorrect.\n");
    }
    
    printf("5. This element has the atomic number 82 and is often used as a radiation shield. ");
    scanf("%d", &answer);
    if (answer == 82) {
        printf("Correct!\n");
        score += 10;
    } else {
        printf("Incorrect.\n");
    }
    
    printf("\nCongratulations! You have completed the quiz.\n");
    printf("Your score is: %d/50\n", score);
    
    return 0;
}