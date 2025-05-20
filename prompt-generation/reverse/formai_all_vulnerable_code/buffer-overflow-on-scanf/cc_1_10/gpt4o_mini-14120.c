//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PARTICIPANTS 4
#define MAX_TURNS 10

typedef struct {
    char name[50];
    int score;
} Participant;

void initializeParticipants(Participant participants[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of participant %d: ", i + 1);
        scanf("%s", participants[i].name);
        participants[i].score = 0;
    }
}

void printScores(Participant participants[], int count) {
    printf("\n--- Current Scores ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d points\n", participants[i].name, participants[i].score);
    }
}

int rollDice() {
    return (rand() % 6) + 1;
}

void playTurn(Participant *participant) {
    printf("\n%s's turn to roll the dice...\n", participant->name);
    int diceRoll = rollDice();
    participant->score += diceRoll;
    printf("%s rolled a %d! Total score: %d\n", participant->name, diceRoll, participant->score);
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    Participant participants[MAX_PARTICIPANTS];
    int numParticipants;

    printf("Welcome to the Romantic Dice Game!\n");
    printf("Where love and luck intertwine!\n");
    printf("How many participants will grace this occasion (1-4)? ");
    scanf("%d", &numParticipants);

    if (numParticipants < 1 || numParticipants > MAX_PARTICIPANTS) {
        printf("Invalid number of participants. Exiting...\n");
        return 1;
    }

    initializeParticipants(participants, numParticipants);

    for (int turn = 0; turn < MAX_TURNS; turn++) {
        printf("\n--- Turn %d ---\n", turn + 1);
        for (int i = 0; i < numParticipants; i++) {
            playTurn(&participants[i]);
        }
        printScores(participants, numParticipants);
    }

    printf("\n--- Final Results ---\n");
    int highestScore = 0;
    for (int i = 0; i < numParticipants; i++) {
        if (participants[i].score > highestScore) {
            highestScore = participants[i].score;
        }
    }

    printf("The ultimate Romantic Champion(s):\n");
    for (int i = 0; i < numParticipants; i++) {
        if (participants[i].score == highestScore) {
            printf("%s with %d points!\n", participants[i].name, participants[i].score);
        }
    }

    printf("\nThank you for playing the Romantic Dice Game!\n");
    printf("May your hearts be filled with joy and laughter!\n");

    return 0;
}