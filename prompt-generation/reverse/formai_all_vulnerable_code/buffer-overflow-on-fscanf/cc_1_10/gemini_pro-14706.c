//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: visionary
// Dive into the Cosmic Tapestry of Log Analytics

#include <stdio.h>
#include <stdlib.h>

// Our celestial orb of analyzed data
typedef struct LogOrb {
    char* timestamp;
    char* message;
    int severity;
} LogOrb;

// A cosmic dance of log orbs
LogOrb* logOrbs;
int numOrbs;

// Our cosmic oracle, the log analyzer
void analyzeLogs() {
    // We traverse the celestial sphere...
    for (int i = 0; i < numOrbs; i++) {
        // ...and gaze upon each radiant orb
        LogOrb* orb = &logOrbs[i];
        printf("%s - %s (Severity: %d)\n", orb->timestamp, orb->message, orb->severity);
    }
}

int main() {
    // Let us conjure a cosmic dance of log orbs...

    // Fetch the celestial chorus from the ethereal expanse
    FILE* logFile = fopen("celestial.log", "r");
    if (!logFile) {
        printf("Oh celestial forces! The log file has vanished!\n");
        return 1;
    }

    // Establish the celestial sphere's dimensions
    numOrbs = 0;
    fscanf(logFile, "%d\n", &numOrbs);
    logOrbs = (LogOrb*)malloc(numOrbs * sizeof(LogOrb));

    // Harvestellar symphony of log orbs
    for (int i = 0; i < numOrbs; i++) {
        LogOrb* orb = &logOrbs[i];
        fscanf(logFile, "%s %s %d\n", orb->timestamp, orb->message, &orb->severity);
    }

    // Invoke our cosmic oracle
    analyzeLogs();

    // When the celestial symphony fades, the stars shall vanish
    fclose(logFile);
    free(logOrbs);

    return 0;
}