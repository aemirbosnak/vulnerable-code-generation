//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
    char element[100];
    int correct = 0;
    int total = 0;
    int score = 0;

    printf("\nWelcome to the C Periodic Table Quiz!\n");
    printf("----------------------------------------\n");
    printf("This quiz will test your knowledge of the elements in the periodic table.\n");
    printf("You will be given the name of an element, and you must enter its atomic number.\n");
    printf("For example, if the element is 'Hydrogen', you would enter '1'.\n");
    printf("Good luck!\n");

    while(1) {
        printf("\n");
        printf("Element %d: ", ++total);
        scanf("%s", element);

        int atomic_number = 0;
        if(strcmp(element, "Hydrogen") == 0) {
            atomic_number = 1;
        } else if(strcmp(element, "Helium") == 0) {
            atomic_number = 2;
        } else if(strcmp(element, "Lithium") == 0) {
            atomic_number = 3;
        } else if(strcmp(element, "Beryllium") == 0) {
            atomic_number = 4;
        } else if(strcmp(element, "Boron") == 0) {
            atomic_number = 5;
        } else if(strcmp(element, "Carbon") == 0) {
            atomic_number = 6;
        } else if(strcmp(element, "Nitrogen") == 0) {
            atomic_number = 7;
        } else if(strcmp(element, "Oxygen") == 0) {
            atomic_number = 8;
        } else if(strcmp(element, "Fluorine") == 0) {
            atomic_number = 9;
        } else if(strcmp(element, "Neon") == 0) {
            atomic_number = 10;
        } else {
            printf("Sorry, that element is not in the quiz.\n");
            continue;
        }

        int user_answer = 0;
        scanf("%d", &user_answer);

        if(user_answer == atomic_number) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", atomic_number);
        }
    }

    printf("\n");
    printf("You got %d out of %d correct.\n", correct, total);
    printf("Your score is %d%%\n", (score = correct * 100 / total));

    return 0;
}