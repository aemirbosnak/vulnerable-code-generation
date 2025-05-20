//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: sophisticated
int main() {
    char text[] = "HELLO WORLD";
    char morse[] = ".... . .-.. .-.. --- ..- --..--";
    char result[100];

    for (int i = 0; i < 100; i++) {
        if (text[i] == ' ') {
            result[i] = ' ';
        } else if (text[i] == 'A') {
            result[i] = '.-';
        } else if (text[i] == 'B') {
            result[i] = '-...';
        } else if (text[i] == 'C') {
            result[i] = '-.-.';
        } else if (text[i] == 'D') {
            result[i] = '-..';
        } else if (text[i] == 'E') {
            result[i] = '.';
        } else if (text[i] == 'F') {
            result[i] = '..-.';
        } else if (text[i] == 'G') {
            result[i] = '--.';
        } else if (text[i] == 'H') {
            result[i] = '....';
        } else if (text[i] == 'I') {
            result[i] = '..';
        } else if (text[i] == 'J') {
            result[i] = '.---';
        } else if (text[i] == 'K') {
            result[i] = '-.-';
        } else if (text[i] == 'L') {
            result[i] = '.-..';
        } else if (text[i] == 'M') {
            result[i] = '--';
        } else if (text[i] == 'N') {
            result[i] = '-.';
        } else if (text[i] == 'O') {
            result[i] = '---';
        } else if (text[i] == 'P') {
            result[i] = '.--.';
        } else if (text[i] == 'Q') {
            result[i] = '--.-';
        } else if (text[i] == 'R') {
            result[i] = '.-.';
        } else if (text[i] == 'S') {
            result[i] = '...';
        } else if (text[i] == 'T') {
            result[i] = '-';
        } else if (text[i] == 'U') {
            result[i] = '..-';
        } else if (text[i] == 'V') {
            result[i] = '...-';
        } else if (text[i] == 'W') {
            result[i] = '.--';
        } else if (text[i] == 'X') {
            result[i] = '-..-';
        } else if (text[i] == 'Y') {
            result[i] = '-.--';
        } else if (text[i] == 'Z') {
            result[i] = '--..';
        } else {
            result[i] = '\0';
        }
    }

    printf("%s\n", result);

    return 0;
}