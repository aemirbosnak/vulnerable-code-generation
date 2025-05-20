//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for storing voting data
struct VotingData {
    char name[50];
    int age;
    char party[50];
};

// Function to read voting data from file
void readVotingData(char* filename, struct VotingData* data) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %d %s", data[i].name, &data[i].age, data[i].party) != EOF) {
        i++;
    }
    fclose(fp);
}

// Function to generate a random number
int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to shuffle an array
void shuffleArray(int* arr, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = randomNumber(0, i);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to print the voting results
void printVotingResults(struct VotingData* data, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s (%d): %s\n", data[i].name, data[i].age, data[i].party);
    }
}

// Function to simulate voting process
void simulateVoting(struct VotingData* data, int size) {
    // Shuffle the array to randomize the voting order
    shuffleArray(data, size);

    // Simulate the voting process
    for (int i = 0; i < size; i++) {
        printf("Voting for %s (%d): %s\n", data[i].name, data[i].age, data[i].party);
    }

    // Print the voting results
    printVotingResults(data, size);
}

int main() {
    // Read voting data from file
    struct VotingData data[100];
    readVotingData("voting_data.txt", data);

    // Simulate voting process
    simulateVoting(data, 100);

    return 0;
}