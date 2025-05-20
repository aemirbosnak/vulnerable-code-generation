//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-esque ASCII art
const char *art =
"                                                                              \n"
"  _.-=""""""""===---....___                                                           \n"
" /   .-'    .   .    _.--'  `-.                                                      \n"
" |   /   .  :   :  /   .'     `.                                                     \n"
"  \  :   :  :    ;\  /        \                                                    \n"
"   `\  :  ;   :  / | |         |                                                   \n"
"     `:  :   ;   :/  | ___     |                                                  \n"
"       \  \  :  ./   (   )   /                                                   \n"
"        `\ \ : /     `-'   .'                                                    \n"
"          `.;'       /    :                                                     \n"
"            /        |    |                                                      \n"
"           :         ;   .'                                                       \n"
"           :     _  | .-'                                                        \n"
"           `.   / \ |.'                                                         \n"
"             | |   | |                                                          \n"
"             | |   | |                                                          \n"
"             | |   : :                                                           \n"
"             : |   | |                                                           \n"
"              \ :  ; |                                                            \n"
"               | :  ; ;                                                           \n"
"               | :  | |                                                           \n"
"               :  ;  ;                                                            \n"
"                \  | |                                                             \n"
"                 ||.  ;                                                             \n"
"                 || | :                                                              \n"
"                 ||  ;                                                               \n"
"                 | |  |                                                                \n"
"               .-'  : |                                                                 \n"
"              /      :                                                                  \n"
"             ;        :                                                                 \n"
"            /          ;                                                                 \n"
"           /           |                                                                 \n"
"          ;            ;                                                                \n"
"         /             |                                                                \n"
"        |              ;                                                               \n"
"       |               |                                                                \n"
"       |               :\033[0;31m CYBERPUNK HEXADECIMAL CONVERTER \033[0;37m                                                 \n"
"       |               :\033[0;31m-----------------------------\033[0;37m                                                \n"
"       |               ;                                                                \n"
"       |               /                                                                 \n"
"        ;              |                                                                 \n"
"         \             :                                                                 \n"
"          |            ;                                                                \n"
"           |           :\033[0;31m Please enter a hexadecimal number: \033[0;37m                                  \n"
"            :           |                                                                \n"
"             |          ;                                                               \n"
"              \        /                                                                 \n"
"               |      /                                                                  \n"
"               :     ;                                                                   \n"
"                \   /                                                                    \n"
"                 | /                                                                     \n"
"                 ||                                                                      \n"
"                 |/                                                                       \n"
"                .L                                                                        \n"
"                 |                                                                         \n"
"                :                                                                          \n"
"               /                                                                           \n"
"              ;                                                                            \n"
"             /                                                                             \n"
"            |                                                                              \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"           |                                                                               \n"
"     \033[0;31m/=======================================================================================\033[0;37m     \n"
"                                                                                         ";
// Function to convert hexadecimal to decimal
int hex_to_dec(char *hex) {
  int dec = 0;
  int len = strlen(hex);
  for (int i = 0; i < len; i++) {
    int digit = hex[i] - '0';
    if (digit > 9) {
      digit -= 7;
    }
    dec = dec * 16 + digit;
  }
  return dec;
}

// Function to convert decimal to hexadecimal
char *dec_to_hex(int dec) {
  char *hex = malloc(100);
  int i = 0;
  while (dec != 0) {
    int remainder = dec % 16;
    if (remainder > 9) {
      remainder += 7;
    }
    hex[i] = remainder + '0';
    dec /= 16;
    i++;
  }
  hex[i] = '\0';
  int len = strlen(hex);
  for (int j = 0; j < len / 2; j++) {
    char temp = hex[j];
    hex[j] = hex[len - j - 1];
    hex[len - j - 1] = temp;
  }
  return hex;
}

int main() {
  // Print the ASCII art
  printf("%s", art);

  // Get the input hexadecimal number
  char hex[100];
  scanf("%s", hex);

  // Convert the hexadecimal number to decimal
  int dec = hex_to_dec(hex);

  // Print the decimal number
  printf("\033[0;31mDecimal: %d\033[0;37m\n", dec);

  // Convert the decimal number to hexadecimal
  char *new_hex = dec_to_hex(dec);

  // Print the new hexadecimal number
  printf("\033[0;31mHexadecimal: %s\033[0;37m\n", new_hex);

  return 0;
}