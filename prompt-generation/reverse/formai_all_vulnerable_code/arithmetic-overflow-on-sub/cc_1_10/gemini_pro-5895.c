//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
// Where secret love and bitter fate collide,
// A medical store's secrets shall we guide.

#include <stdio.h>
#include <stdlib.h>

// Two houses, both alike in dignity,
struct Montague {
  int code;
  char *name;
  float price;
  int quantity;
};

struct Capulet {
  int code;
  char *name;
  float price;
  int quantity;
};

// In fair Verona, where our scene is laid,
struct Verona {
  struct Montague *Montague;
  struct Capulet *Capulet;
  int MontagueCount;
  int CapuletCount;
};

// From forth the fatal loins of these two foes,
struct Romeo {
  struct Verona *verona;
  int idx;
};

struct Juliet {
  struct Verona *verona;
  int idx;
};

// Create a new Montague, fair as the sun,
struct Montague *CreateMontague(int code, char *name, float price, int quantity) {
  struct Montague *Montague = malloc(sizeof(struct Montague));
  Montague->code = code;
  Montague->name = name;
  Montague->price = price;
  Montague->quantity = quantity;
  return Montague;
}

// Create a new Capulet, bright as the moon,
struct Capulet *CreateCapulet(int code, char *name, float price, int quantity) {
  struct Capulet *Capulet = malloc(sizeof(struct Capulet));
  Capulet->code = code;
  Capulet->name = name;
  Capulet->price = price;
  Capulet->quantity = quantity;
  return Capulet;
}

// Create a new Verona, where love shall bloom,
struct Verona *CreateVerona() {
  struct Verona *verona = malloc(sizeof(struct Verona));
  verona->Montague = NULL;
  verona->Capulet = NULL;
  verona->MontagueCount = 0;
  verona->CapuletCount = 0;
  return verona;
}

// Add a Montague to the fray, their love proclaimed,
void AddMontague(struct Verona *verona, struct Montague *Montague) {
  verona->Montague = realloc(verona->Montague, (verona->MontagueCount + 1) * sizeof(struct Montague));
  verona->Montague[verona->MontagueCount++] = *Montague;
}

// Add a Capulet to the mix, their passion ignited,
void AddCapulet(struct Verona *verona, struct Capulet *Capulet) {
  verona->Capulet = realloc(verona->Capulet, (verona->CapuletCount + 1) * sizeof(struct Capulet));
  verona->Capulet[verona->CapuletCount++] = *Capulet;
}

// Romeo, Romeo, wherefore art thou Romeo,
struct Romeo *CreateRomeo(struct Verona *verona) {
  struct Romeo *Romeo = malloc(sizeof(struct Romeo));
  Romeo->verona = verona;
  Romeo->idx = -1;
  return Romeo;
}

// Juliet, Juliet, thy beauty doth undo me,
struct Juliet *CreateJuliet(struct Verona *verona) {
  struct Juliet *Juliet = malloc(sizeof(struct Juliet));
  Juliet->verona = verona;
  Juliet->idx = -1;
  return Juliet;
}

// If Montague be written in the book of Love,
int FindMontague(struct Romeo *Romeo, int code) {
  for (int i = 0; i < Romeo->verona->MontagueCount; i++) {
    if (Romeo->verona->Montague[i].code == code) {
      return i;
    }
  }
  return -1;
}

// If Capulet be written in the book of Love,
int FindCapulet(struct Juliet *Juliet, int code) {
  for (int i = 0; i < Juliet->verona->CapuletCount; i++) {
    if (Juliet->verona->Capulet[i].code == code) {
      return i;
    }
  }
  return -1;
}

// Romeo, thy love doth ask for medicine,
void RomeoAsk(struct Romeo *Romeo, int code, int quantity) {
  int idx = FindMontague(Romeo, code);
  if (idx == -1) {
    printf("No such medicine in thy fair Verona.\n");
    return;
  }

  if (Romeo->verona->Montague[idx].quantity < quantity) {
    printf("Alas, fair Juliet, we lack the stock.\n");
    return;
  }

  Romeo->idx = idx;
  Romeo->verona->Montague[idx].quantity -= quantity;
  printf("Thy medicine, fair Juliet, take and be well.\n");
}

// Juliet, thy beauty doth ask for medicine,
void JulietAsk(struct Juliet *Juliet, int code, int quantity) {
  int idx = FindCapulet(Juliet, code);
  if (idx == -1) {
    printf("No such medicine in thy fair Verona.\n");
    return;
  }

  if (Juliet->verona->Capulet[idx].quantity < quantity) {
    printf("Alas, fair Romeo, we lack the stock.\n");
    return;
  }

  Juliet->idx = idx;
  Juliet->verona->Capulet[idx].quantity -= quantity;
  printf("Thy medicine, fair Romeo, take and be well.\n");
}

// For never was a story of more woe,
void PrintTragedy(struct Romeo *Romeo, struct Juliet *Juliet) {
  if (Romeo->idx != -1 && Juliet->idx != -1) {
    printf("Thus with a kiss, I die.\n");
    printf("And with a kiss, I die.\n");
  } else {
    printf("O, I am fortune's fool!\n");
  }
}

int main() {
  struct Verona *verona = CreateVerona();

  // Add Montagues and Capulets to our fair city,
  AddMontague(verona, CreateMontague(1, "Romeo", 10, 10));
  AddMontague(verona, CreateMontague(2, "Juliet", 15, 15));
  AddMontague(verona, CreateMontague(3, "Mercutio", 5, 5));

  AddCapulet(verona, CreateCapulet(4, "Tybalt", 12, 12));
  AddCapulet(verona, CreateCapulet(5, "Paris", 18, 18));
  AddCapulet(verona, CreateCapulet(6, "Friar Laurence", 20, 20));

  // Create Romeo and Juliet, two souls entwined,
  struct Romeo *Romeo = CreateRomeo(verona);
  struct Juliet *Juliet = CreateJuliet(verona);

  // Romeo asks for medicine, his love in need,
  RomeoAsk(Romeo, 2, 10);

  // Juliet asks for medicine, her love's request,
  JulietAsk(Juliet, 1, 5);

  // Print the tragic end, their love's sweet kiss,
  PrintTragedy(Romeo, Juliet);

  // Free the memory, their story told,
  free(Romeo);
  free(Juliet);
  free(verona);

  return 0;
}