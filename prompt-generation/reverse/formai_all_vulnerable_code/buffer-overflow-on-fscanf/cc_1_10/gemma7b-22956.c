//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Case Files
  FILE *fp1 = fopen("CaseFile1.txt", "r");
  FILE *fp2 = fopen("CaseFile2.txt", "r");

  // Characters
  char **SuspectList = (char **)malloc(10 * sizeof(char *));
  SuspectList[0] = "Mr. A";
  SuspectList[1] = "Mrs. B";
  SuspectList[2] = "Mr. C";
  SuspectList[3] = "Mrs. D";
  SuspectList[4] = "Mr. E";
  SuspectList[5] = "Mrs. F";
  SuspectList[6] = "Mr. G";
  SuspectList[7] = "Mrs. H";
  SuspectList[8] = "Mr. I";
  SuspectList[9] = "Mr. J";

  // Evidence
  char **EvidenceList = (char **)malloc(20 * sizeof(char *));
  EvidenceList[0] = "Bloodstained weapon";
  EvidenceList[1] = "Footprints";
  EvidenceList[2] = "Wounds on victim";
  EvidenceList[3] = "Broken window";
  EvidenceList[4] = "Stained clothing";
  EvidenceList[5] = "Fingerprints";
  EvidenceList[6] = "Blood trail";
  EvidenceList[7] = "Broken vase";
  EvidenceList[8] = "Bloody footprints";
  EvidenceList[9] = "Stained rope";
  EvidenceList[10] = "A piece of hair";
  EvidenceList[11] = "A broken watch";
  EvidenceList[12] = "A shattered mirror";
  EvidenceList[13] = "A spilled drink";
  EvidenceList[14] = "A broken flowerpot";
  EvidenceList[15] = "A trail of blood";
  EvidenceList[16] = "A broken window latch";
  EvidenceList[17] = "A bloody knife";
  EvidenceList[18] = "A broken lock";
  EvidenceList[19] = "A stained glass window";

  // Investigation
  char *Suspect = NULL;
  char *Evidence = NULL;

  // Read case files and analyze evidence
  fscanf(fp1, "%s", Suspect);
  fscanf(fp2, "%s", Evidence);

  // Compare evidence to suspect list and identify the culprit
  for (int i = 0; i < 10; i++) {
    if (strcmp(SuspectList[i], Suspect) == 0) {
      Suspect = SuspectList[i];
      break;
    }
  }

  // Conclusion
  printf("The suspect is: %s", Suspect);

  fclose(fp1);
  fclose(fp2);
  free(SuspectList);
  free(EvidenceList);

  return 0;
}