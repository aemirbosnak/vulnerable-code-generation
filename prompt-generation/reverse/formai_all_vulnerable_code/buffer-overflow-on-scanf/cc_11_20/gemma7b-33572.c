//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Scene: The grand library of 221B Baker Street.

    // Characters: Sherlock Holmes and John Watson.

    // Game Objective: Solve a murder mystery.

    // Game Setup:

    char suspect_1 = 'A';
    char suspect_2 = 'B';
    char suspect_3 = 'C';
    char suspect_4 = 'D';
    char suspect_5 = 'E';

    int evidence_1 = 0;
    int evidence_2 = 1;
    int evidence_3 = 0;
    int evidence_4 = 1;
    int evidence_5 = 0;

    // Game Start:

    printf("You are Sherlock Holmes, and you have been called to a murder mystery at 221B Baker Street.\n");
    printf("A wealthy businessman, Mr. Bartholomew, has been found dead in his study.\n");
    printf("Please enter your command: ");

    char command[20];

    scanf("%s", command);

    // Analyze the command:

    if (strcmp(command, "Examine") == 0)
    {
        printf("You examine the scene carefully. You find a number of clues, including:");
        printf("\n");
        if (evidence_1)
        {
            printf("- A bloodstained letter from Mr. Bartholomew to suspect_1.\n");
        }
        if (evidence_2)
        {
            printf("- A broken vase.\n");
        }
        if (evidence_3)
        {
            printf("- A bloody fingerprint on the murder weapon.\n");
        }
        if (evidence_4)
        {
            printf("- A trail of blood leading from the study to the hallway.\n");
        }
        if (evidence_5)
        {
            printf("- A broken window.\n");
        }
    }
    else if (strcmp(command, "Question") == 0)
    {
        printf("You question the suspects. They give you the following information:");
        printf("\n");
        printf("Suspect_1: %c is a ruthless businessman who has a history of infidelity.\n", suspect_1);
        printf("Suspect_2: %c is a loyal employee who is known for his quick wit and honesty.\n", suspect_2);
        printf("Suspect_3: %c is a jealous rival who has a grudge against Mr. Bartholomew.\n", suspect_3);
        printf("Suspect_4: %c is a suspicious character who has been seen lurking around the house.\n", suspect_4);
        printf("Suspect_5: %c is a nervous maid who is known for her quick nervous movements.\n", suspect_5);
    }
    else if (strcmp(command, "Conclude") == 0)
    {
        // Analyze the evidence and make a deduction:

        printf("Based on your deductions, I believe that Mr. Bartholomew was murdered by...");
        printf("\n");
        if (evidence_1 && evidence_3)
        {
            printf("%c. He was stabbed to death with the broken window glass.\n", suspect_1);
        }
        else if (evidence_2 && evidence_4)
        {
            printf("%c. He was strangled to death with the broken vase.\n", suspect_2);
        }
        else if (evidence_3 && evidence_5)
        {
            printf("%c. He was shot to death with the bloody fingerprint on the murder weapon.\n", suspect_3);
        }
        else if (evidence_4 && evidence_1)
        {
            printf("%c. He was bludgeoned to death with the bloodstained letter from Mr. Bartholomew to suspect_1.\n", suspect_4);
        }
        else if (evidence_5 && evidence_2)
        {
            printf("%c. He was stabbed to death with the broken vase.\n", suspect_5);
        }
    }

    return 0;
}