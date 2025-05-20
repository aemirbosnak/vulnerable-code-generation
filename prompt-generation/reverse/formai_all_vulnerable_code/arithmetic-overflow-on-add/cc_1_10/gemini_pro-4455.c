//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: introspective
// Embark on an introspective journey into the realm of electronic democracy with this thought-provoking C program.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The ballot box, a keeper of secrets and the foundation of our virtual democracy.
struct BallotBox {
    char **candidates;
    int numCandidates;
    int *votes;
};

// The voter's enlightened choice, shaping the electoral landscape.
struct Vote {
    int candidateIndex;
    int isValid;
};

// A sentinel to guide us, ensuring the integrity of our virtual ballot box.
#define INVALID_CANDIDATE -1

// A tapestry of functions, each a thread in the intricate fabric of our voting system.

// Initialize the ballot box, a vessel for our collective voice.
struct BallotBox *initBallotBox(char **candidates, int numCandidates) {
    struct BallotBox *box = malloc(sizeof(struct BallotBox));
    box->candidates = candidates;
    box->numCandidates = numCandidates;
    box->votes = calloc(numCandidates, sizeof(int));
    return box;
}

// Cast a vote, a voice resonating in the virtual chamber.
struct Vote castVote(struct BallotBox *box, int candidateIndex) {
    struct Vote vote;
    vote.isValid = (candidateIndex >= 0 && candidateIndex < box->numCandidates);
    if (vote.isValid) {
        box->votes[candidateIndex]++;
    }
    vote.candidateIndex = candidateIndex;
    return vote;
}

// Tally the votes, revealing the collective will of our virtual electorate.
void tallyVotes(struct BallotBox *box) {
    int maxVotes = 0;
    int winnerIndex = -1;

    for (int i = 0; i < box->numCandidates; i++) {
        if (box->votes[i] > maxVotes) {
            maxVotes = box->votes[i];
            winnerIndex = i;
        }
    }

    if (winnerIndex != -1) {
        printf("The winner is: %s\n", box->candidates[winnerIndex]);
    } else {
        printf("No candidate received a majority of votes.\n");
    }
}

// A beacon of transparency, illuminating the electoral process.
void printVotes(struct BallotBox *box) {
    for (int i = 0; i < box->numCandidates; i++) {
        printf("%s: %d votes\n", box->candidates[i], box->votes[i]);
    }
}

// Our virtual polling station, where ideas compete and democracy takes form.
int main() {
    // The candidates, voices vying for support.
    char *candidates[] = { "Ada Lovelace", "Alan Turing", "Grace Hopper", "Steve Jobs" };
    int numCandidates = sizeof(candidates) / sizeof(candidates[0]);

    // Initialize the ballot box, the custodian of our collective choice.
    struct BallotBox *box = initBallotBox(candidates, numCandidates);

    // Cast a few votes, shaping the electoral landscape.
    castVote(box, 0);
    castVote(box, 2);
    castVote(box, 3);
    castVote(box, 1);
    castVote(box, INVALID_CANDIDATE);

    // Tally the votes, revealing the collective will of our virtual electorate.
    tallyVotes(box);

    // Print the votes, casting light on the electoral outcome.
    printVotes(box);

    // Free the memory allocated for the ballot box, releasing its hold on our virtual democracy.
    free(box->candidates);
    free(box->votes);
    free(box);

    return 0;
}