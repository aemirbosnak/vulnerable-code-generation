//Code Llama-13B DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
int main() {
    // Variables
    int currentRoom = 1;
    int correctAnswers = 0;
    int totalRooms = 5;

    // Welcome message
    printf("Welcome to the Haunted House Simulator!\n");

    // Room 1: The Entrance
    printf("You find yourself standing in front of a creepy old mansion.\n");
    printf("The wind howls and the trees sway ominously in the distance.\n");
    printf("You can see the entrance to the mansion through the open doors.\n");
    printf("Do you want to (1) go inside or (2) explore the surrounding area? ");
    scanf("%d", &currentRoom);

    // Room 2: The Hallway
    if (currentRoom == 2) {
        printf("You decide to explore the surrounding area.\n");
        printf("You see a dense forest to the east and a dark cave to the west.\n");
        printf("Which direction do you want to go? (1) East or (2) West? ");
        scanf("%d", &currentRoom);
    }

    // Room 3: The Forest
    if (currentRoom == 1) {
        printf("You enter the forest.\n");
        printf("The trees are tall and the underbrush is thick.\n");
        printf("You hear strange noises in the distance.\n");
        printf("Do you want to (1) continue through the forest or (2) turn back? ");
        scanf("%d", &currentRoom);
    }

    // Room 4: The Cave
    if (currentRoom == 2) {
        printf("You enter the cave.\n");
        printf("The air is damp and you can hear the sound of dripping water.\n");
        printf("You see a glowing portal in the distance.\n");
        printf("Do you want to (1) go through the portal or (2) explore the cave? ");
        scanf("%d", &currentRoom);
    }

    // Room 5: The Final Room
    if (currentRoom == 1 || currentRoom == 2) {
        printf("You approach the portal.\n");
        printf("Suddenly, you hear a loud noise and the portal closes.\n");
        printf("You are trapped!\n");
        printf("Do you want to (1) try to open the portal again or (2) give up? ");
        scanf("%d", &currentRoom);
    }

    // Game Over
    if (currentRoom == 1 || currentRoom == 2) {
        printf("Game Over\n");
        printf("You made it out of the haunted house alive!\n");
        printf("You got %d out of %d questions correct.\n", correctAnswers, totalRooms);
    }

    return 0;
}