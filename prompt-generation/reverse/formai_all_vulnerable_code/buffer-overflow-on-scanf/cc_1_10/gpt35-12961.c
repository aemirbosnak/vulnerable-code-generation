//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the Network Topology Mapper!\n");

    // Setting up variables
    int numDevices, numConnections;
    printf("How many devices do we need to map?: ");
    scanf("%d", &numDevices);
    printf("Now tell me, how many connections should we expect?: ");
    scanf("%d", &numConnections);

    // Mapping Devices
    printf("\nLet's start mapping!\n");
    printf("=====================\n");
    printf("               ___\n");
    printf("   __________/ o \\___________\n");
    printf("  /                           \\\n");
    for(int i = 0; i < numDevices - 1; i++) {
        printf("  |       ___________       |\n");
        printf("  |      |           |      |\n");
        printf("  |______|    %02d     |______|\n", i+1);
        printf("         |___________|\n");
        printf("                 |\n");
        printf("                 |\n");
        printf("                 |\n");
        printf("                 |\n");
        printf("                 |\n");
        printf("                 V\n");
    }
    printf("  |       ___________       |\n");
    printf("  |      |           |      |\n");
    printf("  |______|    %02d     |______|\n", numDevices);
    printf("         |___________|\n");

    // Adding connections
    printf("\nNow let's add some connections!\n");
    printf("==============================\n");
    int device1, device2;
    for(int i = 0; i < numConnections; i++) {
        printf("\nConnection %d\n", i+1);
        printf("Connect device #: ");
        scanf("%d", &device1);
        printf("To device #: ");
        scanf("%d", &device2);

        if(device1 == device2) {
            printf("\nYou cannot connect a device to itself! Try again.\n");
            i--;
            continue;
        }
        if(device1 > numDevices || device2 > numDevices) {
            printf("\nInvalid device numbers! Try again.\n");
            i--;
            continue;
        }

        // Adding link
        printf("\nConnecting device %d to device %d...\n", device1, device2);
        printf("                ___________\n");
        printf("Device %02d------|           |------Device %02d\n", device1, device2);
        printf("                |___________|\n");

        // Confirmation message
        printf("\nConnection between Device %02d and Device %02d established!\n", device1, device2);
    }

    printf("\nAll done! Happy mapping :)");
    return 0;
}