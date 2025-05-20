//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Cyberpunk-style definitions
#define RUN "Execute"
#define QUIT "Jack Out"
#define EXAM "Network Assessment"
#define QUESTIONS "Datapacks"
#define CORRECT "Packet Captured"
#define INCORRECT "Signal Lost"
#define SCORE "Access Level"

// Exam questions and answers
const char *questions[] = {
    "Identify the protocol used for remote desktop access.",
    "Which port is typically used for HTTP traffic?",
    "What is the purpose of a firewall?",
    "What is the difference between a virus and a worm?",
    "What is the name of the vulnerability that allows an attacker to execute arbitrary code on a system?",
    "What is the purpose of a honeypot?",
    "Which type of encryption is used to secure data in transit?",
    "What is the difference between a hash and a MAC?",
    "What is the purpose of a network intrusion detection system (NIDS)?",
    "What is the name of the protocol used for email delivery?"
};

const char *answers[] = {
    "RDP",
    "80",
    "To control access to a network",
    "A virus infects files, while a worm replicates itself across networks",
    "Buffer overflow",
    "To lure attackers and collect information on their techniques",
    "TLS/SSL",
    "A hash is a one-way function, while a MAC is a keyed hash",
    "To detect and respond to network attacks",
    "SMTP"
};

// Main function
int main() {
    // Cyberpunk-style intro
    printf("Welcome to the %s, runner.\n", EXAM);
    printf("Prepare to interface with %d %s.\n", sizeof(questions) / sizeof(questions[0]), QUESTIONS);
    printf("RUN to start, %s to disconnect.\n\n", QUIT);

    // Input buffer
    char input[32];

    // User input
    printf("> ");
    scanf("%s", input);

    // Start the exam
    if (strcmp(input, RUN) == 0) {
        // Initialize score
        int score = 0;

        // Loop over questions
        for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
            // Display question
            printf("%s\n", questions[i]);

            // Get user answer
            scanf("%s", input);

            // Check answer
            if (strcmp(input, answers[i]) == 0) {
                printf("%s\n\n", CORRECT);
                score++;
            } else {
                printf("%s\n\n", INCORRECT);
            }
        }

        // Display score
        printf("%s: %d%%\n\n", SCORE, (score * 100) / (sizeof(questions) / sizeof(questions[0])));
    }

    // Quit the exam
    else if (strcmp(input, QUIT) == 0) {
        printf("Exiting %s.\n", EXAM);
    }

    // Invalid input
    else {
        printf("Invalid command. Please enter RUN or %s.\n", QUIT);
    }

    return 0;
}