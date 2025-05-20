//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// Define a Struct for Element
struct Element {
    char symbol[3];
    char name[50];
    int atomic_number;
};

//Prototype for Quiz Function
void quiz(struct Element arr[], int n);

int main() {
    // Virtual Periodic Elements Array
    struct Element elements[] = {
        {"H", "Hydrogen", 1},
        {"He", "Helium", 2},
        {"Li", "Lithium", 3},
        {"Be", "Beryllium", 4},
        {"B", "Boron", 5},
        {"C", "Carbon", 6},
        //Add more elements
    };
    int n = sizeof(elements)/sizeof(elements[0]); //Size of array
    printf("                             --- PERIODIC TABLE QUIZ ---\n\n");
    printf("INSTRUCTIONS:\n");
    printf("1. This Quiz contains %d questions related to the Periodic Table.\n", n);
    printf("2. Each question contains 4 options.\n");
    printf("3. Choose the correct option number (1, 2, 3 or 4) and press Enter.\n");
    printf("4. Your score will be displayed at the end of the Quiz.\n\n");

    // Call Quiz Function
    quiz(elements, n);

    return 0;
}

void quiz(struct Element arr[], int n) {
    int score = 0;
    srand(time(0));  // Seed the generator
    for(int i=0; i<n; i++) {
        //Randomly generate options for each question
        int a = rand()%n;
        int b = rand()%n;
        int c = rand()%n;
        while(a==i || b==i || c==i || a==b || a==c || b==c) {
            a = rand()%n;
            b = rand()%n;
            c = rand()%n;
        }
        printf("Q%d) %s is the symbol for which element?\n", i+1, arr[i].name);
        printf("1) %s\n", arr[i].symbol);
        printf("2) %s\n", arr[a].symbol);
        printf("3) %s\n", arr[b].symbol);
        printf("4) %s\n", arr[c].symbol);
        int answer;
        printf("Enter your answer (1/2/3/4): ");
        scanf("%d", &answer);
        if(answer == 1) {
            printf("Correct Answer! +1 point. \n\n");
            score++;
        }
        else {
            printf("Wrong Answer! The correct answer is %s. \n\n", arr[i].symbol);
        }
    }
    printf("\nRESULTS:\n");
    printf("Your Score: %d out of %d.\n", score, n);
    if(score == n) {
        printf("Congratulations! You have a perfect score!\n");
    }
}