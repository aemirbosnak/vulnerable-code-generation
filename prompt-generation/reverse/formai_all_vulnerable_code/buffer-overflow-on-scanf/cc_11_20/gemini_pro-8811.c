//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Watson, the trusty sidekick
#define WATSON "Watson"

// Define the case file for this investigation
#define CASE_FILE "smart_home_automation"

// Declare the suspects (devices)
#define SUSPECT_LIGHTS "Lights"
#define SUSPECT_THERMOSTAT "Thermostat"
#define SUSPECT_DOORBELL "Doorbell"

// Define the possible motives (actions)
#define MOTIVE_TURN_ON "Turn on"
#define MOTIVE_TURN_OFF "Turn off"
#define MOTIVE_SET_TEMPERATURE "Set temperature"
#define MOTIVE_ANSWER "Answer"

// Define the clues (user input)
#define CLUE_DETECTED_MOTION "Motion detected"
#define CLUE_DOORBELL_RINGING "Doorbell ringing"
#define CLUE_TEMPERATURE_CHANGED "Temperature changed"
#define CLUE_VOICE_COMMAND "Voice command"

// Define the alibi (device status)
#define ALIBI_ON "On"
#define ALIBI_OFF "Off"
#define ALIBI_TEMPERATURE "Temperature"

// Sherlock's deductions
#define DEDUCTION_INTRUDER "Intruder alert!"
#define DEDUCTION_VISITOR "Visitor detected!"
#define DEDUCTION_TEMPERATURE_ADJUSTMENT "Temperature change requested."

// The main investigation function
int main() {
    // Set the scene
    printf("My dear Watson, gather your magnifying glass and analytical mind. We have a perplexing case of smart home automation to solve.\n");

    // Collect the clues
    char clue[50];
    printf("Watson: What clues have we uncovered?\n");
    printf("Enter clue: ");
    scanf("%s", clue);

    // Examine the suspects
    char suspect[50];
    printf("Watson: Which suspect is under suspicion?\n");
    printf("Enter suspect: ");
    scanf("%s", suspect);

    // Deduce the motive
    char motive[50];
    if (strcmp(clue, CLUE_DETECTED_MOTION) == 0) {
        strcpy(motive, MOTIVE_TURN_ON);
    } else if (strcmp(clue, CLUE_DOORBELL_RINGING) == 0) {
        strcpy(motive, MOTIVE_ANSWER);
    } else if (strcmp(clue, CLUE_TEMPERATURE_CHANGED) == 0) {
        strcpy(motive, MOTIVE_SET_TEMPERATURE);
    } else if (strcmp(clue, CLUE_VOICE_COMMAND) == 0) {
        printf("Watson: What was the voice command?\n");
        printf("Enter command: ");
        scanf("%s", motive);
    }

    // Check the alibi
    char alibi[50];
    if (strcmp(suspect, SUSPECT_LIGHTS) == 0) {
        printf("Watson: Are the lights currently %s or %s?\n", ALIBI_ON, ALIBI_OFF);
        printf("Enter alibi: ");
        scanf("%s", alibi);
    } else if (strcmp(suspect, SUSPECT_THERMOSTAT) == 0) {
        printf("Watson: What is the current temperature setting?\n");
        printf("Enter alibi: ");
        scanf("%s", alibi);
    } else if (strcmp(suspect, SUSPECT_DOORBELL) == 0) {
        strcpy(alibi, ALIBI_OFF);
    }

    // Present the deductions
    if (strcmp(clue, CLUE_DETECTED_MOTION) == 0 && strcmp(suspect, SUSPECT_LIGHTS) == 0 && strcmp(motive, MOTIVE_TURN_ON) == 0) {
        printf("Elementary, my dear Watson! An intruder has triggered the motion sensor, and the lights should be turned on.\n");
    } else if (strcmp(clue, CLUE_DOORBELL_RINGING) == 0 && strcmp(suspect, SUSPECT_DOORBELL) == 0 && strcmp(motive, MOTIVE_ANSWER) == 0) {
        printf("It appears we have a visitor at the door, Watson. Let us answer the doorbell.\n");
    } else if (strcmp(clue, CLUE_TEMPERATURE_CHANGED) == 0 && strcmp(suspect, SUSPECT_THERMOSTAT) == 0 && strcmp(motive, MOTIVE_SET_TEMPERATURE) == 0) {
        printf("The temperature has been adjusted, Watson. I trust you have a good reason for this.\n");
    } else {
        printf("Hmm... this case remains puzzling, Watson. Further investigation is required.\n");
    }

    // Update the case file
    FILE *case_file = fopen(CASE_FILE, "a");
    fprintf(case_file, "Suspect: %s\n", suspect);
    fprintf(case_file, "Clue: %s\n", clue);
    fprintf(case_file, "Motive: %s\n", motive);
    fprintf(case_file, "Deduction: %s\n\n", DEDUCTION_INTRUDER);
    fclose(case_file);

    // Conclude the investigation
    printf("Watson: Another case solved with your assistance. I trust you will keep my methods confidential, as always.");
    return 0;
}