//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A lively antivirus scanner, ready to detect those pesky viruses!

// Our trusty virus database, packed with signatures to sniff out the bad guys
const char *virus_signatures[] = {
    "EvilVirus123",
    "MaliciousMalware777",
    "DangerousTrojan555",
    "SuspiciousWorm999"
};

// The number of virus signatures we're tracking
const int num_signatures = sizeof(virus_signatures) / sizeof(virus_signatures[0]);

// Our friendly function to scan a file for viruses
int scan_file(const char *filename) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Oops! Can't open the file. Maybe it's hiding from us? Try again!");
        return 1; // Something went wrong, so we'll return an error code
    }

    // Time to get serious and start scanning!
    char buffer[1024]; // A buffer to hold chunks of the file
    while (fgets(buffer, sizeof(buffer), file)) {
        // For each line in the file, let's compare it to our virus signatures
        for (int i = 0; i < num_signatures; i++) {
            if (strstr(buffer, virus_signatures[i])) {
                // Uh-oh, we found a virus!
                printf("Gotcha! Virus detected: %s\n", virus_signatures[i]);
                fclose(file);
                return 2; // We'll return a special code to indicate a virus was found
            }
        }
    }

    // No viruses detected, so let's give the file a clean bill of health
    printf("All clear! No viruses found in %s.\n", filename);
    fclose(file);
    return 0; // Everything's okay, so we'll return a success code
}

int main() {
    // Let's get ready to rock and scan some files!
    char filename[100];
    printf("Enter the file you want to scan: ");
    scanf("%s", filename);

    // Fire up the scanner!
    int result = scan_file(filename);

    // Depending on the result, we'll give an appropriate response
    if (result == 0) {
        printf("Whew! Your file is safe and sound.");
    } else if (result == 1) {
        printf("Sorry, we couldn't scan your file. Maybe give us another try?");
    } else if (result == 2) {
        printf("Uh-oh, your file has a nasty virus! Delete it immediately!");
    }

    return 0;
}