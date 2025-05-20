//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: romantic
#include <stdio.h>
#include <string.h>

#define ROWS 6 // Height of character
#define COLS 6 // Width of character

/* ASCII forms of the characters */
char A[ROWS][COLS+1] = {"  A  ", " / \\ ", "|   |", "|---|", "|   |", "|   |"};
char B[ROWS][COLS+1] = {" ____", "|    \\", "|_____\\", "|     \\", "|_____/",""};
char C[ROWS][COLS+1] = {"  ___", " /   ", "|    ", "|    ", " \\___", ""};
char D[ROWS][COLS+1] = {" ___ ", "|   \\", "|    |", "|    |", "|___/", ""};
char E[ROWS][COLS+1] = {" ____", "|     ", "|___ ", "|     ", "|____", ""};
char F[ROWS][COLS+1] = {" ____", "|     ", "|___ ", "|     ", "|     ", ""};
char G[ROWS][COLS+1] = {"  ___", " /   ", "|  __", "|   |", " \\__,|", ""};
char H[ROWS][COLS+1] = {"      ","|     |", "|-----|", "|     |", "|     |", ""};
char I[ROWS][COLS+1] = {" _ ", "| |", "| |", "| |", "|_|", ""};
char J[ROWS][COLS+1] = {"     _", "    | ", "    | ", " /\\__/ ", "|    | ", " \\__/  "};
char K[ROWS][COLS+1] = {"      ", "|     \\", "|__ / <", "|    / ", "|     \\", ""};
char L[ROWS][COLS+1] = {"     ", "|    ", "|    ", "|    ", "|____", ""};
char M[ROWS][COLS+1] = {"      ", "|\\   /|", "| \\ / |", "|     |", "|     |", ""};
char N[ROWS][COLS+1] = {"      ", "|\\    |", "|  \\  |", "|   \\ |", "|    \\|", ""};
char O[ROWS][COLS+1] = {"  ___", " /   \\", "|     |", "|     |", " \\___/", ""};
char P[ROWS][COLS+1] = {"____ ", "|    \\", "|_____\\", "|      ", "|      ", ""};
char Q[ROWS][COLS+1] = {"  ___ ", " /   \\", "|     |", "|  \\ /|", " \\_/ \\|", ""};
char R[ROWS][COLS+1] = {"____ ", "|    \\", "|____/", "|    \\", "|     \\", ""};
char S[ROWS][COLS+1] = {"  __ ", " /__ ", "    |", " ___/", " \\__\\", ""};
char T[ROWS][COLS+1] = {" ____", "|_   ", " |   ", " |   ", " |___", ""};
char U[ROWS][COLS+1] = {"      ", "|     |", "|     |", "|     |", " \\___/ ", ""};
char V[ROWS][COLS+1] = {"      ", "\\     /", " \\   / ", "  \\ /  ", "   |   ", ""};
char W[ROWS][COLS+1] = {"          ", "\\       /", " \\  /\\  / ", "  \\//\\\\/  ", "   |  |   ", ""};
char X[ROWS][COLS+1] = {"      ", "\\     /", "  \\___/ ", "  /   \\ ", "/_ _\\  \\", ""};
char Y[ROWS][COLS+1] = {"      ", "\\     /", " \\___/ ", "  |   ", "  |   ", ""};
char Z[ROWS][COLS+1] = {" ____", "/___/", "    / ", "   /  ", "  /___", ""};
char SPACE[ROWS][COLS+1] = {"   ", "   ", "   ", "   ", "   ", ""};

void print_line(char art[]) // Print a line of characters
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < strlen(art); j++)
        {
            printf("%c%s", art[j], SPACE[i]); // Print character followed by 5 spaces
        }
        printf("\n");
    }
}

int main()
{
    char input[50];
    printf("Enter a phrase: ");
    scanf("%s", input);
    printf("\n");

    // Loop through each character in input string
    for (int i = 0; i < strlen(input); i++)
    {
        char c = input[i];

        // Determine which ASCII art array to use based on character
        switch (c)
        {
            case 'A': print_line(A); break;
            case 'B': print_line(B); break;
            case 'C': print_line(C); break;
            case 'D': print_line(D); break;
            case 'E': print_line(E); break;
            case 'F': print_line(F); break;
            case 'G': print_line(G); break;
            case 'H': print_line(H); break;
            case 'I': print_line(I); break;
            case 'J': print_line(J); break;
            case 'K': print_line(K); break;
            case 'L': print_line(L); break;
            case 'M': print_line(M); break;
            case 'N': print_line(N); break;
            case 'O': print_line(O); break;
            case 'P': print_line(P); break;
            case 'Q': print_line(Q); break;
            case 'R': print_line(R); break;
            case 'S': print_line(S); break;
            case 'T': print_line(T); break;
            case 'U': print_line(U); break;
            case 'V': print_line(V); break;
            case 'W': print_line(W); break;
            case 'X': print_line(X); break;
            case 'Y': print_line(Y); break;
            case 'Z': print_line(Z); break;
            default: printf(" "); break;
        }
    }

    return 0;
}