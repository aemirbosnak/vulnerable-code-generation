//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    int choice, haunted_house_num, floor_num, room_num;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Welcome to the Haunted House Simulator, %s. Choose an haunted house number:**\n", name);
    printf("1. The Blackwood Mansion\n");
    printf("2. The Thornfield Hall\n");
    printf("3. The Briarstone Manor\n");
    scanf("%d", &haunted_house_num);

    printf("Choose a floor number: ");
    scanf("%d", &floor_num);

    printf("Choose a room number: ");
    scanf("%d", &room_num);

    switch (haunted_house_num)
    {
        case 1:
            printf("You have chosen the Blackwood Mansion, a notorious haunted house with a dark and sinister past. The spirits of the Blackwood Mansion are known to torment their victims with ghostly illusions, cruel whispers, and even physical harm. Prepare for a terrifying experience.\n");
            break;
        case 2:
            printf("You have chosen the Thornfield Hall, a haunted house steeped in tragedy. The spirits of Thornfield Hall include a vengeful young woman, a tormented child, and a cold-hearted demon. Prepare for a ghostly encounter that will send shivers down your spine.\n");
            break;
        case 3:
            printf("You have chosen the Briarstone Manor, a haunted house filled with tormented souls. The spirits of Briarstone Manor include a wicked witch, a greedy businessman, and a vengeful soldier. Prepare for a haunting that will leave you trembling in fear.\n");
            break;
    }

    switch (floor_num)
    {
        case 1:
            printf("You have chosen the first floor, where the spirits dwell and torment their victims. Prepare for ghostly whispers, eerie shadows, and a feeling of dread.\n");
            break;
        case 2:
            printf("You have chosen the second floor, where the spirits are known to appear in front of you, tormenting you with their presence and their evil eyes. Prepare for a terrifying encounter.\n");
            break;
        case 3:
            printf("You have chosen the third floor, where the spirits are said to be the most active. Prepare for a ghostly presence that will make your blood run cold.\n");
            break;
    }

    switch (room_num)
    {
        case 1:
            printf("You have chosen room 1, a sinister chamber where the spirits gather to feed on their victims. Prepare for ghostly visions, cruel whispers, and a feeling of dread.\n");
            break;
        case 2:
            printf("You have chosen room 2, a haunted bedroom where the spirits of the deceased slumber. Prepare for ghostly encounters, eerie noises, and a feeling of unease.\n");
            break;
        case 3:
            printf("You have chosen room 3, a bloody corridor where the spirits of war fought their final battle. Prepare for ghostly screams, bloodstained walls, and a feeling of terror.\n");
            break;
    }

    printf("Thank you for visiting the Haunted House Simulator, %s. We hope you enjoyed your ghostly encounter.", name);
}