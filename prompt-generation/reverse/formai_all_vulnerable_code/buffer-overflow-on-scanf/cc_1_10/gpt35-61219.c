//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char * elements[] = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al",
                     "Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn",
                     "Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
                     "Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag",
                     "Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce",
                     "Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm",
                     "Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg",
                     "Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa",
                     "U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No",
                     "Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh",
                     "Fl","Mc","Lv","Ts","Og"};

char * elementNames[] = {"Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon","Nitrogen",
                         "Oxygen","Fluorine","Neon","Sodium","Magnesium","Aluminium","Silicon",
                         "Phosphorus","Sulfur","Chlorine","Argon","Potassium","Calcium","Scandium",
                         "Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt","Nickel",
                         "Copper","Zinc","Gallium","Germanium","Arsenic","Selenium","Bromine",
                         "Krypton","Rubidium","Strontium","Yttrium","Zirconium","Niobium","Molybdenum",
                         "Technetium","Ruthenium","Rhodium","Palladium","Silver","Cadmium","Indium",
                         "Tin","Antimony","Tellurium","Iodine","Xenon","Caesium","Barium","Lanthanum",
                         "Cerium","Praseodymium","Neodymium","Promethium","Samarium","Europium",
                         "Gadolinium","Terbium","Dysprosium","Holmium","Erbium","Thulium","Ytterbium",
                         "Lutetium","Hafnium","Tantalum","Tungsten","Rhenium","Osmium","Iridium",
                         "Platinum","Gold","Mercury","Thallium","Lead","Bismuth","Polonium",
                         "Astatine","Radon","Francium","Radium","Actinium","Thorium","Protactinium",
                         "Uranium","Neptunium","Plutonium","Americium","Curium","Berkelium","Californium",
                         "Einsteinium","Fermium","Mendelevium","Nobelium","Lawrencium","Rutherfordium",
                         "Dubnium","Seaborgium","Bohrium","Hassium","Meitnerium","Darmstadtium",
                         "Roentgenium","Copernicium","Nihonium","Flerovium","Moscovium","Livermorium",
                         "Tennessine","Oganesson"};

int main(){
    srand(time(NULL)); // initialize random seed
    
    int score = 0;
    
    for(int i=0; i<10; i++){ // 10 questions
        
        int randNum = rand()%118;
        char *element = elements[randNum]; 
        char answer[20];

        printf("Question %d: What is the name of the element with symbol %s?\n",i+1,element);
        
        // get user input
        scanf("%s",answer);
        
        // check if answer is correct
        if(strcmp(elementNames[randNum],answer) == 0){
            printf("Correct!\n");
            score++;
        }else{
            printf("Incorrect. The answer is %s.\n",elementNames[randNum]);
        }
    } 
    
    printf("Final score: %d out of 10\n",score);
    return 0;
}