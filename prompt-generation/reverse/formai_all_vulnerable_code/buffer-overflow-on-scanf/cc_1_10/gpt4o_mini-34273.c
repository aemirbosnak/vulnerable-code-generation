//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the romantic gesture details
typedef struct {
    char gesture[50]; // The romantic gesture
    int votes;        // Number of votes received
} Gesture;

// Function to display the romantic gestures
void displayGestures(Gesture gestures[], int numGestures) {
    printf("\n🌹 Cast Your Vote for the Most Romantic Gesture! 🌹\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < numGestures; i++) {
        printf("%d. %s\n", i + 1, gestures[i].gesture);
    }
    printf("-------------------------------------------------------\n");
}

// Function to find the winner
void findWinner(Gesture gestures[], int numGestures) {
    int maxVotes = 0, winnerIndex = -1;
    for (int i = 0; i < numGestures; i++) {
        if (gestures[i].votes > maxVotes) {
            maxVotes = gestures[i].votes;
            winnerIndex = i;
        }
    }
    printf("\n❤️ The Most Romantic Gesture is: \"%s\" with %d votes! ❤️\n", 
           gestures[winnerIndex].gesture, gestures[winnerIndex].votes);
}

int main() {
    int numGestures = 5;
    Gesture gestures[5] = {
        {"A candlelight dinner"},
        {"Writing a love letter"},
        {"Taking a sunset walk"},
        {"Gifting flowers"},
        {"Cooking a meal together"}
    };

    int choice;
    char continueVoting;

    printf("\n❤️ Welcome to the Romantic Voting System ❤️\n");

    do {
        displayGestures(gestures, numGestures);
        printf("🎉 Enter the number of your favorite gesture (1-%d): ", numGestures);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= numGestures) {
            gestures[choice - 1].votes++; // Increment the vote count for selected gesture
            printf("✅ Thank you for casting your vote! 🌟\n");
        } else {
            printf("❌ Invalid choice, my love! 💔 Please try again.\n");
        }

        printf("✍️ Do you wish to continue voting? (y/n): ");
        scanf(" %c", &continueVoting);

    } while (continueVoting == 'y' || continueVoting == 'Y');

    // Display the results
    printf("\n🌼 Voting has ended! Here are the results: 🌼\n");
    for (int i = 0; i < numGestures; i++) {
        printf("%s: %d votes\n", gestures[i].gesture, gestures[i].votes);
    }

    // Find and display the winner
    findWinner(gestures, numGestures);
    
    return 0;
}