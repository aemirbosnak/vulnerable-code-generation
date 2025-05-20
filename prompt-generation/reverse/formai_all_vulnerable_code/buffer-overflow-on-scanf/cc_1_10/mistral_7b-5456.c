//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define Turing machine states
enum { IDLE, F_INPUT, C_OUTPUT, HALT };

// Define Turing machine symbols
enum { BLANK, F, C };

// Define Turing machine tape
#define TAPE_SIZE 100
char tape[TAPE_SIZE];
int head_pos = 0;

// Define Turing machine functions
void print_tape() {
  int i;
  printf("Tape: ");
  for (i = head_pos - 10; i <= head_pos + 10 && i >= 0; i--) {
    printf("%c ", tape[i] == '\0' ? BLANK : tape[i] == F ? 'F' : 'C');
  }
  printf("\nHead position: %d", head_pos);
}

void move_left() {
  if (head_pos > 0)
    head_pos--;
}

void move_right() {
  head_pos++;
}

void write_symbol(char symbol) {
  tape[head_pos] = symbol;
  head_pos++;
}

void read_symbol() {
  if (head_pos > 0)
    printf("Symbol read: %c\n", tape[head_pos - 1]);
  else
    printf("No symbol to read.\n");
}

void turing_machine_converter() {
  int state = IDLE;

  while (state != HALT) {
    print_tape();
    switch (state) {
      case IDLE:
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &tape[head_pos]);
        write_symbol(F);
        move_right();
        state = F_INPUT;
        break;

      case F_INPUT:
        read_symbol();
        tape[head_pos - 1] = '\0';
        float fahrenheit = atof(tape);
        write_symbol(BLANK);
        move_right();
        write_symbol('x');
        move_right();
        state = C_OUTPUT;
        break;

      case C_OUTPUT:
        read_symbol();
        if (tape[head_pos - 1] == 'x') {
          float celsius = (fahrenheit - 32) * 5.0 / 9.0;
          char temp_str[20];
          snprintf(temp_str, sizeof(temp_str), "%.2f°C", celsius);
          for (int i = 0; temp_str[i] != '\0'; i++) {
            write_symbol(temp_str[i]);
            move_right();
          }
          state = HALT;
        } else {
          move_left();
          state = F_INPUT;
        }
        break;
    }
  }
}

int main() {
  turing_machine_converter();
  printf("\nDone!\n");
  return 0;
}