//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Dreamland of Adobe Screens
#define DIMENSION 10
#define THRESHOLD 5

typedef struct {
    char* username;
    char* action;
    time_t timestamp;
} Intrusion;

void conjure_intrusion(Intrusion* intrusive);
void dance_with_intruders(Intrusion* cracking);
void whisper_errors(Intrusion* hint);
void unveil_the_assault(Intrusion* attack);
void draw_anomaly_map(Intrusion* point);

int main() {
    srand(time(0));

    // Array of ominous intrusions
    Intrusion shadows[DIMENSION];
    for (int i = 0; i < DIMENSION; i++) {
        conjure_intrusion(&shadows[i]);
    }

    // Dreamy detection mechanic
    for (int j = 0; j < DIMENSION; j++) {
        dance_with_intruders(&shadows[j]);
    }

    // Searching for whispers in the void
    for (int k = 0; k < DIMENSION; k++) {
        whisper_errors(&shadows[k]);
    }

    // Unveiling the specter
    for (int m = 0; m < DIMENSION; m++) {
        unveil_the_assault(&shadows[m]);
    }

    return 0;
}

void conjure_intrusion(Intrusion* intrusive) {
    char* usernames[] = {"Alice", "Bob", "Eve", "Mallory", "Trent"};
    char* actions[] = {"Login", "Upload", "Delete", "Modify", "Access"};
    int index_user = rand() % 5;
    int index_action = rand() % 5;

    intrusive->username = usernames[index_user];
    intrusive->action = actions[index_action];
    intrusive->timestamp = time(0) - (rand() % 10000); // Random time in the past
}

void dance_with_intruders(Intrusion* cracking) {
    if (rand() % 10 < 5) {
        printf("A waltz of mischief with %s performing a %s at %s", 
            cracking->username, cracking->action, ctime(&cracking->timestamp));
    } else {
        printf("The presence of %s freezes the moonlight.\n", cracking->username);
    }
}

void whisper_errors(Intrusion* hint) {
    if (strcmp(hint->action, "Upload") == 0) {
        printf("Beware, shadows loom! %s uploaded the whispers of night.\n", hint->username);
    } else if (strcmp(hint->action, "Delete") == 0) {
        printf("A black hole emerged as %s tried to delete the past.\n", hint->username);
    }
}

void unveil_the_assault(Intrusion* attack) {
    static int warning_count = 0;
    warning_count++;

    if (warning_count > THRESHOLD) {
        printf("ALARM! Too many intrusions. The fabric of reality is tearing!\n");
        draw_anomaly_map(attack);
    } else {
        printf("A minor damage detected: %s, action: %s\n", attack->username, attack->action);
    }
}

void draw_anomaly_map(Intrusion* point) {
    char* map[DIMENSION][DIMENSION] = {{" ", " ", " ", " ", " "},
                                       {" ", " ", " ", " ", " "},
                                       {" ", " ", " ", " ", " "},
                                       {" ", " ", " ", " ", " "},
                                       {" ", " ", " ", " ", " "}};

    int x = rand() % DIMENSION;
    int y = rand() % DIMENSION;

    map[x][y][0] = '*'; // Marking the intrusion on the map
    printf("Anomaly Map:\n");
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            printf("%s ", map[i][j]);
        }
        printf("\n");
    }
}