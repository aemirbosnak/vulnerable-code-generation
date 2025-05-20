//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_num = 0;
    int result = 0;
    int face_num = 0;

    printf("Enter the number of rolls: ");
    scanf("%d", &roll_num);

    for (roll_num; roll_num > 0; roll_num--)
    {
        result = rand() % 6 + 1;
        face_num = result;

        switch (face_num)
        {
            case 1:
                printf("Face: Number One\n");
                break;
            case 2:
                printf("Face: Number Two\n");
                break;
            case 3:
                printf("Face: Number Three\n");
                break;
            case 4:
                printf("Face: Number Four\n");
                break;
            case 5:
                printf("Face: Number Five\n");
                break;
            case 6:
                printf("Face: Number Six\n");
                break;
        }

        printf("Roll again? (y/n): ");
        char answer = getchar();

        if (answer == 'n')
        {
            break;
        }
    }

    printf("Thank you for playing! Your total number of rolls is: %d\n", roll_num);

    return 0;
}