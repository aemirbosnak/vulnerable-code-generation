//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Cryptic
#include<stdio.h>
#include<string.h>

// Function to create a cryptic periodic table quiz
void cryptic_periodic_table_quiz() {
    printf("-----------------------\n");
    printf("   Cryptic Periodic Table Quiz   \n");
    printf("-----------------------\n");
    printf("Decode the following hints to guess the element symbol:\n\n");

    // The hints and answers array with cryptic message
    char hints[10][50] = {"Snake, Rat's Tail, Tin Can", "Lightweight, Angry Cat, Feline", 
                          "Large Dog, King's Crown, Shards", "Minium Deposit, Chemical Engineer's Initials, Sulfur's Romance Partner", 
                          "Robin's Home, Motorcycle, Nobleman's Title", "Hell's Entrance, Fourth Letter of Alphabet, Element's Number", 
                          "Big Cat, Number of Elements Present, Royalty", "Iron-Man's Alter Ego, Jewel, Second Letter of Alphabet", 
                          "Fruit, Month of Independence, Blank Document", "Breath of Life, Letter before 'I', SLEEP"};
    char answers[10][3] = {"Sn", "Al", "Cs", "Cu", "Au", "Be", "Kr", "Fe", "Pb", "O"};

    // Array to mark which hints have been used
    int used_hints[10] = {0};

    // Loop until all hints have been used
    for (int i = 0; i < 10; i++) {
        // Choose a random unused hint
        int hint_index;
        do {
            hint_index = rand() % 10;
        } while (used_hints[hint_index]);

        printf("Hint %d: %s\n", i+1, hints[hint_index]);

        // Collect user input and convert to uppercase
        char user_answer[3];
        printf("What is the element symbol? ");
        scanf("%s", user_answer);
        for (int j = 0; j < strlen(user_answer); j++) {
            user_answer[j] = toupper(user_answer[j]);
        }

        // Check if the answer is correct
        if (strcmp(user_answer, answers[hint_index]) == 0) {
            printf("Correct!\n\n");
        } else {
            printf("Wrong. The correct answer is %s.\n\n", answers[hint_index]);
        }

        // Mark the hint as used
        used_hints[hint_index] = 1;
    }
}

// Main function to run the quiz
int main() {
    cryptic_periodic_table_quiz();
    return 0;
}