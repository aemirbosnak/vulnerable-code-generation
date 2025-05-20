//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: surrealist
#include <stdio.h>

int main() {
  int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

  printf("Periodic Table Quiz!\n\n");

  printf("Group I: Alkali Metals\n");
  printf("Na (Sodium)\n");
  printf("K (Potassium)\n");
  printf("Li (Lithium)\n\n");

  printf("Group II: Alkaline Earth Metals\n");
  printf("Mg (Magnesium)\n");
  printf("Ca (Calcium)\n");
  printf("Sr (Strontium)\n\n");

  printf("Group VII: Halogens\n");
  printf("F (Fluorine)\n");
  printf("Cl (Chlorine)\n");
  printf("Br (Bromine)\n");
  printf("I (Iodine)\n\n");

  printf("Group VIII: Noble Gases\n");
  printf("He (Helium)\n");
  printf("Ar (Argon)\n");
  printf("Ne (Neon)\n");
  printf("Kr (Krypton)\n");
  printf("Rn (Radon)\n\n");

  printf("Enter the number of the element you want to know about:");
  scanf("%d", &i);

  switch (i) {
    case 1:
      printf("Element: Sodium\n");
      printf("Atomic number: 11\n");
      printf("Atomic mass: 22.989769\n");
      break;
    case 2:
      printf("Element: Potassium\n");
      printf("Atomic number: 19\n");
      printf("Atomic mass: 39.098303\n");
      break;
    case 3:
      printf("Element: Lithium\n");
      printf("Atomic number: 3\n");
      printf("Atomic mass: 6.940922\n");
      break;
    case 4:
      printf("Element: Magnesium\n");
      printf("Atomic number: 12\n");
      printf("Atomic mass: 24.30500\n");
      break;
    case 5:
      printf("Element: Calcium\n");
      printf("Atomic number: 20\n");
      printf("Atomic mass: 40.077000\n");
      break;
    case 6:
      printf("Element: Strontium\n");
      printf("Atomic number: 38\n");
      printf("Atomic mass: 87.6688\n");
      break;
    case 7:
      printf("Element: Fluorine\n");
      printf("Atomic number: 9\n");
      printf("Atomic mass: 18.998403\n");
      break;
    case 8:
      printf("Element: Chlorine\n");
      printf("Atomic number: 17\n");
      printf("Atomic mass: 35.45262\n");
      break;
    case 9:
      printf("Element: Bromine\n");
      printf("Atomic number: 35\n");
      printf("Atomic mass: 79.90440\n");
      break;
    case 10:
      printf("Element: Iodine\n");
      printf("Atomic number: 53\n");
      printf("Atomic mass: 126.90320\n");
      break;
    default:
      printf("Invalid element number.\n");
  }

  return 0;
}