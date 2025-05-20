//Code Llama-13B DATASET v1.0 Category: Haunted House Simulator ; Style: optimized
void main() {
    // Declare variables
    int door, room, haunted, ghost;
    char choice;

    // Initialize variables
    door = 1;
    room = 1;
    haunted = 0;
    ghost = 0;

    // Start the game
    printf("Welcome to the Haunted House Simulator\n");
    printf("You are in room %d\n", room);
    printf("There is a door to the east and a door to the west\n");
    printf("Which door do you choose? (e/w): ");
    scanf("%c", &choice);

    // Process user input
    if (choice == 'e') {
        door = 2;
    } else if (choice == 'w') {
        door = 3;
    } else {
        printf("Invalid input\n");
        return;
    }

    // Check if the room is haunted
    if (room == 1 || room == 2) {
        haunted = 1;
    }

    // Check if the ghost is in the room
    if (room == 2) {
        ghost = 1;
    }

    // Display the results
    printf("You chose door %d\n", door);
    if (haunted) {
        printf("The room is haunted\n");
        if (ghost) {
            printf("A ghost is in the room\n");
        }
    } else {
        printf("The room is not haunted\n");
    }

    // Update the room number
    room++;

    // Check if the game is over
    if (room > 5) {
        printf("You have escaped the haunted house\n");
        return;
    }

    // Prompt the user to continue
    printf("Would you like to continue? (y/n): ");
    scanf("%c", &choice);

    // Check if the user wants to continue
    if (choice == 'y') {
        main();
    } else {
        printf("Goodbye\n");
        return;
    }
}