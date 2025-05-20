//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Arrays of conspiracy theory topics and subtopics
char *topics[] = {"Aliens", "Government", "Illuminati", "JFK", "Moon Landing", "9/11", "Bigfoot", "Loch Ness Monster"};
char *subtopics_aliens[] = {"UFO sightings", "Alien abductions", "Extraterrestrial life", "Government cover-ups"};
char *subtopics_government[] = {"Secret societies", "Mind control", "Black ops", "False flag operations"};
char *subtopics_illuminati[] = {"Control of the world", "New World Order", "Puppet governments", "Symbolism in popular culture"};
char *subtopics_jfk[] = {"Assassination plot", "Cover-up by government agencies", "Conspiracy theories surrounding Lee Harvey Oswald"};
char *subtopics_moon_landing[] = {"Hoax staged by NASA", "Evidence of faked footage", "Motive for faking the landing"};
char *subtopics_911[] = {"Inside job by the government", "Controlled demolition of the World Trade Center", "Foreknowledge of the attacks"};
char *subtopics_bigfoot[] = {"Eyewitness accounts", "Physical evidence (footprints, hair)", "Government suppression of information"};
char *subtopics_loch_ness_monster[] = {"Sightings in Loch Ness", "Photographs and sonar readings", "Tourist attraction or hoax?"};

// Function to generate a random conspiracy theory
void generate_conspiracy_theory() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Select a random topic
    int topic_index = rand() % 8;
    char *topic = topics[topic_index];

    // Select a random subtopic for the chosen topic
    int subtopic_index;
    switch (topic_index) {
        case 0:
            subtopic_index = rand() % 4;
            break;
        case 1:
            subtopic_index = rand() % 4;
            break;
        case 2:
            subtopic_index = rand() % 4;
            break;
        case 3:
            subtopic_index = rand() % 3;
            break;
        case 4:
            subtopic_index = rand() % 3;
            break;
        case 5:
            subtopic_index = rand() % 3;
            break;
        case 6:
            subtopic_index = rand() % 2;
            break;
        case 7:
            subtopic_index = rand() % 2;
            break;
    }
    char *subtopic;
    switch (topic_index) {
        case 0:
            subtopic = subtopics_aliens[subtopic_index];
            break;
        case 1:
            subtopic = subtopics_government[subtopic_index];
            break;
        case 2:
            subtopic = subtopics_illuminati[subtopic_index];
            break;
        case 3:
            subtopic = subtopics_jfk[subtopic_index];
            break;
        case 4:
            subtopic = subtopics_moon_landing[subtopic_index];
            break;
        case 5:
            subtopic = subtopics_911[subtopic_index];
            break;
        case 6:
            subtopic = subtopics_bigfoot[subtopic_index];
            break;
        case 7:
            subtopic = subtopics_loch_ness_monster[subtopic_index];
            break;
    }

    // Generate a random conspiracy theory using the selected topic and subtopic
    char *conspiracy_theory;
    switch (topic_index) {
        case 0:
            conspiracy_theory = malloc(100);
            sprintf(conspiracy_theory, "The government is hiding evidence of extraterrestrial life and is using UFO sightings as a cover-up for their own secret space program.");
            break;
        case 1:
            conspiracy_theory = malloc(100);
            sprintf(conspiracy_theory, "The Illuminati, a secret society of powerful elites, controls the world behind the scenes and manipulates events to their own advantage.");
            break;
        case 2:
            conspiracy_theory = malloc(100);
            sprintf(conspiracy_theory, "The moon landing was faked by NASA to boost American morale and demonstrate superiority over the Soviet Union.");
            break;
        case 3:
            conspiracy_theory = malloc(100);
            sprintf(conspiracy_theory, "The CIA was involved in the assassination of JFK to prevent him from exposing government secrets.");
            break;
        case 4:
            conspiracy_theory = malloc(100);
            sprintf(conspiracy_theory, "The 9/11 attacks were an inside job by the government to justify military action in the Middle East.");
            break;
        case 5:
            conspiracy_theory = malloc(100);
            sprintf(conspiracy_theory, "Bigfoot is a hoax created by the government to distract the public from real issues.");
            break;
        case 6:
            conspiracy_theory = malloc(100);
            sprintf(conspiracy_theory, "The Loch Ness Monster is a mythical creature used by the Scottish tourism industry to attract visitors.");
            break;
        case 7:
            conspiracy_theory = malloc(100);
            sprintf(conspiracy_theory, "The government is suppressing evidence of mind control experiments conducted on unsuspecting citizens.");
            break;
    }

    // Print the generated conspiracy theory
    printf("Here's your conspiracy theory:\n");
    printf("Topic: %s\n", topic);
    printf("Subtopic: %s\n", subtopic);
    printf("Conspiracy Theory: %s\n", conspiracy_theory);
}

int main() {
    // Generate a random conspiracy theory 5 times
    for (int i = 0; i < 5; i++) {
        generate_conspiracy_theory();
        printf("\n");
    }

    return 0;
}