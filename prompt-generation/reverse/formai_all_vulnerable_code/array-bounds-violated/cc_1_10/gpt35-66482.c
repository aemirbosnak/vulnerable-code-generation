//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INTRUSIONS 100

struct Intrusion {
    int id;
    char type[10];
    char source[50];
    bool active;
};

struct Intrusion intrusionList[MAX_INTRUSIONS];
int nextIntrusionId = 1; // start at 1 to avoid confusion with null

void addIntrusion(char type[], char source[]) {
    struct Intrusion newIntrusion;
    newIntrusion.id = nextIntrusionId;
    nextIntrusionId++;
    strcpy(newIntrusion.type, type);
    strcpy(newIntrusion.source, source);
    newIntrusion.active = true;
    intrusionList[newIntrusion.id - 1] = newIntrusion;
}

void deactivateIntrusion(int id) {
    intrusionList[id - 1].active = false;
    printf("Intrusion %d has been deactivated.\n", id);
}

int main() {
    printf("Welcome to the Intrusion Detection System!\n\n");

    // add some sample intrusions
    addIntrusion("DDoS", "10.0.0.5");
    addIntrusion("SQL Injection", "192.168.1.10");
    addIntrusion("Cross Site Scripting", "172.16.0.101");

    // print out the active intrusions
    printf("Active Intrusions:\n");
    for (int i = 0; i < MAX_INTRUSIONS; i++) {
        if (intrusionList[i].id) { // if the id is not 0 (aka null)
            if (intrusionList[i].active) { // if the intrusion is active
                printf("ID: %d\nType: %s\nSource: %s\n\n", intrusionList[i].id, intrusionList[i].type, intrusionList[i].source);
            }
        } else {
            break; // exit the loop when we hit the end of the list
        }
    }

    // deactivate an intrusion
    printf("Which intrusion would you like to deactivate? (Enter an ID): ");
    int idToDeactivate;
    scanf("%d", &idToDeactivate);
    if (intrusionList[idToDeactivate - 1].id) { // make sure the intrusion actually exists
        deactivateIntrusion(idToDeactivate);
    } else {
        printf("Sorry, that intrusion does not exist.\n");
    }

    printf("\nThank you for using the Intrusion Detection System!\n");

    return 0;
}