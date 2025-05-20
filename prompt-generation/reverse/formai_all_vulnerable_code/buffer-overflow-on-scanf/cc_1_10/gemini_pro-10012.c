//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float (*convert)(float);
  char *name;
} unit_t;

float m_to_cm(float m) { return m * 100; }
float cm_to_m(float cm) { return cm / 100; }
float f_to_c(float f) { return (f - 32) * 5 / 9; }
float c_to_f(float c) { return (c * 9 / 5) + 32; }
float lb_to_kg(float lb) { return lb / 2.205; }
float kg_to_lb(float kg) { return kg * 2.205; }

unit_t units[] = {
  {m_to_cm, "meter to centimeter"},
  {cm_to_m, "centimeter to meter"},
  {f_to_c, "fahrenheit to celsius"},
  {c_to_f, "celsius to fahrenheit"},
  {lb_to_kg, "pound to kilogram"},
  {kg_to_lb, "kilogram to pound"},
};

int main() {
  int choice, i;
  float value;

  printf("Unit Converter\n");
  printf("--------------------\n");
  printf("1. Meter to Centimeter\n");
  printf("2. Centimeter to Meter\n");
  printf("3. Fahrenheit to Celsius\n");
  printf("4. Celsius to Fahrenheit\n");
  printf("5. Pound to Kilogram\n");
  printf("6. Kilogram to Pound\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  if (choice < 1 || choice > 6) {
    printf("Invalid choice. Please choose between 1 and 6.\n");
    return -1;
  }

  printf("Enter the value to convert: ");
  scanf("%f", &value);

  for (i = 0; i < 6; i++) {
    if (i + 1 == choice) {
      printf("%f %s = %f %s\n", value, units[i].name, units[i].convert(value),
             units[(i + 1) % 6].name);
      break;
    }
  }

  return 0;
}