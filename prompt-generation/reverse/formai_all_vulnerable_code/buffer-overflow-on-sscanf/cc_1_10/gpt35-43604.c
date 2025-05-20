//FormAI DATASET v1.0 Category: Data mining ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MIN_SUPPORT 2

// Define struct for frequent itemset
typedef struct {
    int items[MAX_SIZE];
    int support;
    int length;
} Itemset;

// Define struct for association rule
typedef struct {
    Itemset antecedent;
    Itemset consequent;
    float confidence;
} AssociationRule;

// Function to read transaction data from file
int** readTransactionData(char* filename, int* numTransactions, int* numItems) {
    FILE* file = fopen(filename, "r");
    int** transactionData;
    char line[MAX_SIZE];
    int transactionIndex = 0;
    int itemIndex = 0;

    if (file != NULL) {
        // Get number of transactions
        fgets(line, MAX_SIZE, file);
        sscanf(line, "%d", numTransactions);

        // Get number of items
        fgets(line, MAX_SIZE, file);
        sscanf(line, "%d", numItems);

        // Allocate memory for transaction data
        transactionData = (int**)malloc(*numTransactions * sizeof(int*));
        for (int i = 0; i < *numTransactions; i++) {
            transactionData[i] = (int*)malloc(*numItems * sizeof(int));
        }

        // Read transaction data from file
        while (fgets(line, MAX_SIZE, file)) {
            char* ptr = line;
            itemIndex = 0;

            while (*ptr != '\n') {
                int item;
                sscanf(ptr, "%d", &item);
                transactionData[transactionIndex][itemIndex] = item;
                ptr++;

                // Skip comma
                if (*ptr == ',') {
                    ptr++;
                }

                itemIndex++;
            }

            transactionIndex++;
        }

        fclose(file);
    } else {
        printf("File %s not found.\n", filename);
        exit(1);
    }

    return transactionData;
}

// Function to print frequent itemsets
void printFrequentItemsets(Itemset** frequentItemsets, int k) {
    printf("Frequent %d-itemsets:\n", k);

    for (int i = 0; frequentItemsets[i] != NULL; i++) {
        printf("{ ");
        for (int j = 0; j < frequentItemsets[i]->length; j++) {
            printf("%d ", frequentItemsets[i]->items[j]);
        }
        printf("} (support = %d)\n", frequentItemsets[i]->support);
    }
}

// Function to generate candidate itemsets
Itemset** generateCandidateItemsets(Itemset** frequentItemsets, int k) {
    Itemset** candidateItemsets = (Itemset**)malloc(MAX_SIZE * sizeof(Itemset*));
    int numCandidateItemsets = 0;

    for (int i = 0; frequentItemsets[i] != NULL; i++) {
        for (int j = i + 1; frequentItemsets[j] != NULL; j++) {
            // Generate new itemset by combining two frequent itemsets
            Itemset* newItemset = (Itemset*)malloc(sizeof(Itemset));
            int numCommonItems = 0;

            for (int p = 0; p < frequentItemsets[i]->length; p++) {
                for (int q = 0; q < frequentItemsets[j]->length; q++) {
                    if (frequentItemsets[i]->items[p] == frequentItemsets[j]->items[q]) {
                        newItemset->items[numCommonItems] = frequentItemsets[i]->items[p];
                        numCommonItems++;
                        break;
                    }
                }
            }

            // Add non-common items from second frequent itemset
            for (int p = 0; p < frequentItemsets[j]->length; p++) {
                int isCommon = 0;
                for (int q = 0; q < numCommonItems; q++) {
                    if (frequentItemsets[j]->items[p] == newItemset->items[q]) {
                        isCommon = 1;
                        break;
                    }
                }
                if (!isCommon) {
                    newItemset->items[numCommonItems] = frequentItemsets[j]->items[p];
                    numCommonItems++;
                }
            }

            newItemset->length = numCommonItems;

            // Add itemset to candidate itemsets if it is not already present
            int isCandidate = 1;
            for (int p = 0; frequentItemsets[p] != NULL; p++) {
                if (newItemset->length != frequentItemsets[p]->length) {
                    continue;
                }
                int isMatch = 1;
                for (int q = 0; q < newItemset->length; q++) {
                    if (newItemset->items[q] != frequentItemsets[p]->items[q]) {
                        isMatch = 0;
                        break;
                    }
                }
                if (isMatch) {
                    isCandidate = 0;
                    break;
                }
            }
            if (isCandidate) {
                candidateItemsets[numCandidateItemsets] = newItemset;
                numCandidateItemsets++;
            }
        }
    }

    candidateItemsets[numCandidateItemsets] = NULL;

    return candidateItemsets;
}

// Function to count support for itemsets
int countSupport(Itemset** frequentItemsets, int** transactionData, int numTransactions, int k) {
    int count = 0;

    for (int i = 0; i < numTransactions; i++) {
        int isMatch = 1;
        for (int j = 0; j < k; j++) {
            int isFound = 0;
            for (int p = 0; frequentItemsets[p] != NULL; p++) {
                int itemFound = 0;
                for (int q = 0; q < frequentItemsets[p]->length; q++) {
                    if (frequentItemsets[p]->items[q] == transactionData[i][j]) {
                        itemFound = 1;
                        break;
                    }
                }
                if (itemFound) {
                    isFound = 1;
                    break;
                }
            }
            if (!isFound) {
                isMatch = 0;
                break;
            }
        }
        if (isMatch) {
            count++;
        }
    }

    return count;
}

// Function to prune candidate itemsets
Itemset** pruneCandidateItemsets(Itemset** candidateItemsets, int** transactionData, int numTransactions, int k) {
    Itemset** frequentItemsets = (Itemset**)malloc(MAX_SIZE * sizeof(Itemset*));
    int numFrequentItemsets = 0;

    // Count support for each candidate itemset
    for (int i = 0; candidateItemsets[i] != NULL; i++) {
        int support = countSupport(&candidateItemsets[i], transactionData, numTransactions, k);
        if (support >= MIN_SUPPORT) {
            Itemset* frequentItemset = (Itemset*)malloc(sizeof(Itemset));
            frequentItemset->length = candidateItemsets[i]->length;
            frequentItemset->support = support;
            for (int j = 0; j < frequentItemset->length; j++) {
                frequentItemset->items[j] = candidateItemsets[i]->items[j];
            }
            frequentItemsets[numFrequentItemsets] = frequentItemset;
            numFrequentItemsets++;
        }
    }

    frequentItemsets[numFrequentItemsets] = NULL;

    return frequentItemsets;
}

// Function to generate frequent itemsets using Apriori algorithm
Itemset** generateFrequentItemsets(int** transactionData, int numTransactions, int numItems) {
    Itemset** frequentItemsets = (Itemset**)malloc(MAX_SIZE * sizeof(Itemset*));
    Itemset** candidateItemsets = (Itemset**)malloc(MAX_SIZE * sizeof(Itemset*));
    int k = 1;

    // Generate frequent 1-itemsets
    for (int i = 0; i < numItems; i++) {
        Itemset* frequentItemset = (Itemset*)malloc(sizeof(Itemset));
        frequentItemset->items[0] = i;
        frequentItemset->length = 1;
        frequentItemset->support = countSupport(&frequentItemset, transactionData, numTransactions, 1);
        if (frequentItemset->support >= MIN_SUPPORT) {
            frequentItemsets[i] = frequentItemset;
        }
    }

    // Generate frequent itemsets of length 2 or more
    while (frequentItemsets[k - 1] != NULL) {
        candidateItemsets = generateCandidateItemsets(frequentItemsets, k);
        frequentItemsets = pruneCandidateItemsets(candidateItemsets, transactionData, numTransactions, k);
        printFrequentItemsets(frequentItemsets, k);
        k++;
    }

    return frequentItemsets;
}

// Function to sort itemsets by support
void sortItemsetsBySupport(Itemset** itemsets) {
    int numItemsets = 0;
    while (itemsets[numItemsets] != NULL) {
        numItemsets++;
    }

    for (int i = 0; i < numItemsets - 1; i++) {
        for (int j = 0; j < numItemsets - i - 1; j++) {
            if (itemsets[j]->support > itemsets[j + 1]->support) {
                Itemset* temp = itemsets[j];
                itemsets[j] = itemsets[j + 1];
                itemsets[j + 1] = temp;
            }
        }
    }
}

// Function to generate association rules
AssociationRule** generateAssociationRules(Itemset** frequentItemsets, int numTransactions) {
    AssociationRule** associationRules = (AssociationRule**)malloc(MAX_SIZE * sizeof(AssociationRule*));
    int numAssociationRules = 0;

    // Generate association rules for frequent itemsets of length 2 or more
    for (int i = 1; frequentItemsets[i] != NULL; i++) {
        for (int j = 0; j < i; j++) {
            for (int p = 0; p < frequentItemsets[i]->length; p++) {
                Itemset antecedent;
                antecedent.length = p + 1;
                for (int q = 0; q < antecedent.length; q++) {
                    antecedent.items[q] = frequentItemsets[i]->items[q];
                }

                // Check if antecedent contains all items in frequent itemset j
                int isSubset = 1;
                for (int q = 0; q < frequentItemsets[j]->length; q++) {
                    int isFound = 0;
                    for (int r = 0; r < antecedent.length; r++) {
                        if (frequentItemsets[j]->items[q] == antecedent.items[r]) {
                            isFound = 1;
                            break;
                        }
                    }
                    if (!isFound) {
                        isSubset = 0;
                        break;
                    }
                }

                // Generate association rule if antecedent is a subset of the frequent itemset j
                if (isSubset) {
                    Itemset consequent;
                    consequent.length = frequentItemsets[i]->length - antecedent.length;
                    int k = 0;
                    for (int q = 0; q < frequentItemsets[i]->length; q++) {
                        int isFound = 0;
                        for (int r = 0; r < antecedent.length; r++) {
                            if (frequentItemsets[i]->items[q] == antecedent.items[r]) {
                                isFound = 1;
                                break;
                            }
                        }
                        if (!isFound) {
                            consequent.items[k] = frequentItemsets[i]->items[q];
                            k++;
                        }
                    }

                    // Calculate confidence of the association rule
                    float confidence = frequentItemsets[i]->support / (float)frequentItemsets[j]->support;

                    // Add association rule to array
                    AssociationRule* associationRule = (AssociationRule*)malloc(sizeof(AssociationRule));
                    associationRule->antecedent = antecedent;
                    associationRule->consequent = consequent;
                    associationRule->confidence = confidence;
                    associationRules[numAssociationRules] = associationRule;
                    numAssociationRules++;
                }
            }
        }
    }

    associationRules[numAssociationRules] = NULL;

    return associationRules;
}

// Function to print association rules
void printAssociationRules(AssociationRule** associationRules) {
    printf("Association Rules:\n");

    for (int i = 0; associationRules[i] != NULL; i++) {
        printf("{ ");
        for (int j = 0; j < associationRules[i]->antecedent.length; j++) {
            printf("%d ", associationRules[i]->antecedent.items[j]);
        }
        printf("} => { ");
        for (int j = 0; j < associationRules[i]->consequent.length; j++) {
            printf("%d ", associationRules[i]->consequent.items[j]);
        }
        printf("} (confidence = %.2f)\n", associationRules[i]->confidence);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        exit(1);
    }

    int numTransactions;
    int numItems;
    int** transactionData = readTransactionData(argv[1], &numTransactions, &numItems);

    Itemset** frequentItemsets = generateFrequentItemsets(transactionData, numTransactions, numItems);

    sortItemsetsBySupport(frequentItemsets);

    AssociationRule** associationRules = generateAssociationRules(frequentItemsets, numTransactions);

    printAssociationRules(associationRules);

    return 0;
}